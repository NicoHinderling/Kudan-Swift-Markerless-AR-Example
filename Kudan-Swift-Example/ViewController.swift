// Kudan-Swift-Example
//
// Created by Nicolas Hinderling on 4/3/17.
// Copyright © 2017 Nicolas Hinderling. All rights reserved.
//

import KudanAR

enum ArbiTrackState {
    case ARBI_PLACEMENT
    case ARBI_TRACKING
}

class ViewController: ARCameraViewController {
    var model: ARModelNode?
    
    var arbiButtonState: ArbiTrackState = .ARBI_PLACEMENT
    var lastScale: Float = 0
    var lastPanX: Float = 0
    
    override func viewDidLoad() {
        super.viewDidLoad()
    }
    
    override func setupContent() {
        setupModel()
        setupArbiTrack()
        
        let pinchGesture = UIPinchGestureRecognizer(target: self, action: #selector(arbiPinch))
        self.cameraView.addGestureRecognizer(pinchGesture)
        
        let panGesture = UIPanGestureRecognizer(target: self, action: #selector(arbiPan(gesture:)))
        self.cameraView.addGestureRecognizer(panGesture)
        
        let tapGesture = UITapGestureRecognizer(target: self, action: #selector(arbiTap(gesture:)))
        self.cameraView.addGestureRecognizer(tapGesture)
    }
    
    func setupModel() {
        let importer = ARModelImporter(bundled: "footballer_dancing.armodel")
        guard let modelNode = importer?.getNode() else { return }
        
        let modelTexture: ARTexture = ARTexture(uiImage: UIImage(named:"footballer_tex.png"))
        let modelMaterial = ARLightMaterial()
        
        modelMaterial.colour.texture = modelTexture
        modelMaterial.diffuse.value = ARVector3(valuesX: 1, y: 1, z: 1)
        modelMaterial.ambient.value = ARVector3(valuesX: 0.5, y: 0.5, z: 0.5)
        
        guard let meshNodes = modelNode.meshNodes as? [ARMeshNode] else {
            print("setupModel: Error when trying to access model meshNodes")
            return
        }
        
        for meshNode in meshNodes {
            meshNode.material = modelMaterial
        }
        
        modelNode.scale(byUniform: 10)
        modelNode.start()
        modelNode.shouldLoop = true

        self.model = modelNode
    }
    
    func setupArbiTrack() {
        // Initialise gyro placement. Gyro placement positions content on a virtual floor plane where the device is aiming.
        let gyroPlaceManager = ARGyroPlaceManager.getInstance()
        gyroPlaceManager?.initialise()
        
        // Set up the target node on which the model is placed.
        let targetNode: ARNode = ARNode(name: "targetNode")
        gyroPlaceManager?.world.addChild(targetNode)
        
        // Add a visual reticule to the target node for the user.
        let targetImageNode = ARImageNode(image: UIImage(named: "target"))
        targetNode.addChild(targetImageNode)
        
        // Scale and rotate the image to the correct transformation.
        targetImageNode?.scale(byUniform: 0.1)
        targetImageNode?.rotate(byDegrees: 90, axisX: 1, y: 0, z: 0)
        
        // Initialise the arbiTracker, do not start until user placement.
        let arbiTrack = ARArbiTrackerManager.getInstance()
        arbiTrack?.initialise()
        
        // Set the arbiTracker target node to the node moved by the user.
        arbiTrack?.targetNode = targetNode
        arbiTrack?.world.addChild(model)
    }
    
    func arbiTap(gesture: UITapGestureRecognizer) {
        let arbiTrack = ARArbiTrackerManager.getInstance()
        
        if(arbiButtonState == .ARBI_PLACEMENT) {
            arbiTrack?.start()
            arbiTrack?.targetNode.visible = false
            
            self.model?.scale = ARVector3(valuesX: 1, y: 1, z: 1)
            arbiButtonState = .ARBI_TRACKING            
        } else if (arbiButtonState == .ARBI_TRACKING) {
            arbiTrack?.stop()
            arbiTrack?.targetNode.visible = true
            arbiButtonState = .ARBI_PLACEMENT
        }
    }
    
    func arbiPinch(gesture: UIPinchGestureRecognizer) {
        var scaleFactor = Float(gesture.scale)
        
        if(gesture.state == .began) {
            lastScale = 1
        }
        
        scaleFactor = 1 - (lastScale - scaleFactor)
        lastScale = Float(gesture.scale)

        self.model?.scale(byUniform: scaleFactor)
    }
    
    func arbiPan(gesture: UIPanGestureRecognizer) {
        let x = Float(gesture.translation(in: self.cameraView).x)
        
        if(gesture.state == .began) {
            lastPanX = x
        }
        
        let diff = x - lastPanX
        let deg = diff * 0.05

        self.model?.rotate(byDegrees: deg, axisX: 0, y: 1, z: 0)
    } 
}
