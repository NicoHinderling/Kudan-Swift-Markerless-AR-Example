//
//  AppDelegate.swift
//  Kudan-Swift-Example
//
//  Created by Nicolas Hinderling on 4/3/17.
//  Copyright © 2017 Nicolas Hinderling. All rights reserved.
//

import KudanAR

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {

    var window: UIWindow?
    
    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {
        
        // Configure Kudan API
        ARAPIKey.sharedInstance().setAPIKey("MkUMyWpdGfG0KT4wCjDUpVUqn9Y1A7o9P6TJKh9+Lf1WVCT1hbvYMcVfKwRCqQcK4CnHkBv/OXjAJHKSEsCUqBbLi+7Pqs+wpTrzRcFvwpCfc79jM77L45QZVDDREjS6uZNsAnv9O2cJMAQzDfNXqqy6T0dphRS2q38VlZyJHyI/LZzoZc5O0NHpPLodRhl7gzXBHPdlUGL6UKDAIPFaJfGRSLi/gmEK5FUY0pdtU8jbs3F3LBHktqz0BBn/IBW4hQ7oSx494NljGy3mPDmHfJFKuMRJU+hhBX+2/pdph9/kSr3gaIm+e5+szvGqzqPFPWim0ye3Q2MLk9la50H1v1nAqdRrol0j3AA8azj94l7GWv0pSCphYHb1wZT+KfywqUVp9W7wgfrDxJb1gKMJFP7nzyYDqbQBhOndOPBnlmqyOstqDRbMtqJ8sI227pNUmwAj/aQ4UVILzcy2RuxbqM6OTY8Gymx7TDOnvSVQJZoeqnujnSiKnBa3nZzcg0uukycxUD5t8hw5UqfuOifZh+rt0amcDBRCGV5R7jAPPuAtr7pRqNxSpR6Kmf6krLNh/FPT8RQsYEMr3apjmWPS/8DXDDyQu+lZDlKF7Jp7Dfllom24EnTsWWSuTH1PDg3XeYugFrglm3RTjmUjTATRHc/nvB4VEhfQV2mhcVSDuz8=")
        
        return true
    }
}

