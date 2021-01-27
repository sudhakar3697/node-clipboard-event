//
//  clipboard-event-handler-mac.swift
//
//  Created by Joonhee Lee on 2021/01/27.
//

import Foundation
import Cocoa

var count: Int = 0
let pasteboard: NSPasteboard = NSPasteboard.general

repeat{
    usleep(500)
    if(count < pasteboard.changeCount){
        count = pasteboard.changeCount
        print("CLIPBOARD_CHANGE")
        fflush(stdout)
    }
}while true

