//
//  Zombie.swift
//  MonsterTown
//
//  Created by Michel Launier on 2021-01-30.
//

import Foundation

class Zombie : Monster {
    var walkWithLimp: Bool
    private(set) var isFallingApart: Bool
    
    override class var spookyNoise: String {
        return "Brains..."
    }
    
    init(limp: Bool, fallingAppart: Bool, town: Town?, name: String) {
        self.walkWithLimp = limp
        self.isFallingApart = fallingAppart
        super.init(town: town, name: name)
    }
    convenience init(limp: Bool, fallingAppart: Bool) {
        self.init(limp: limp, fallingAppart: fallingAppart, town: nil, name: "Fred")
    }
    required init(town: Town?, name: String) {
        self.walkWithLimp = true
        self.isFallingApart = false
        super.init(town: town, name: name)
    }
    deinit {
        print("Zombie named \(name) is no longer with us.")
    }
    
    final override func terrorizeTown() {
        if !isFallingApart {
            town?.changePopulation(amount: -10)
        }
        super.terrorizeTown()
    }
    
    func changeName(name: String, walkWithLimp: Bool) {
        self.name = name
        self.walkWithLimp = walkWithLimp
    }
}
