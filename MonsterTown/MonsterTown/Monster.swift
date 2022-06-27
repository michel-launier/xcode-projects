//
//  Monster.swift
//  MonsterTown
//
//  Created by Michel Launier on 2021-01-30.
//

import Foundation

class Monster {
    static let isTerrifying = true
    var town: Town?
    var name: String
    class var spookyNoise: String {
        return "Grrr"
    }
    
    var victimPool: Int {
        get {
            return town?.population ?? 0
        }
        set(newVictimPool) {
            town?.population = newVictimPool
        }
    }
    
    required init(town: Town?, name: String) {
        self.town = town
        self.name = name
    }
    func terrorizeTown() {
        if town != nil{
            print("\(name) is terrorizing a town")
        }
        else {
            print("\(name) hasn't found a town to terrorize yet...")
        }
    }
}
