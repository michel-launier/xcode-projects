//
//  Validity.swift
//  theFabric
//
//  Created by Michel Launier on 2023-11-24.
//

import Foundation

protocol Validity {
    func isValid() -> Bool
    func localValidity() -> Bool
    func validityParent() -> Validity?
}

// Provide a default implementation for isValid() & validityParent()
extension Validity {
    func isValid() -> Bool {
        if !localValidity() { return false }
        if let parent = validityParent() {
            return parent.isValid()
        }
        return true
    }
    func validityParent() -> Validity? {
        return nil
    }
}
