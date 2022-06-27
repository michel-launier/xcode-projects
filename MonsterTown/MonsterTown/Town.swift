//
//  Town.swift
//  MonsterTown
//
//  Created by Michel Launier on 2021-01-30.
//

import Foundation

struct Town {
    let region: String
    var population: Int {
        didSet(oldPopulation) {
            print("The population has changed to \(population) from \(oldPopulation); region: \(region).")
        }
    }
    var numberOfStoplights: Int
    
    enum Size {
        case Small
        case Medium
        case Large
    }
    var townSize: Size {
        get {
            switch self.population {
            case 0...10000:
                return Size.Small
            case 10001...100000:
                return Size.Medium
            default:
                return Size.Large
            }
        }
    }
    
    /**
     This is a brief description of the delegate initializer.
     
        - Parameters:
            - region: A rough location of the town
            - population: The initial size of the town population
            - stoplights: Some weird obsession with spotlights
     
     - Version: 0.1

     */
    init?(region: String, population: Int, stoplights: Int) {
        guard population >= 0 else { return nil }
        self.region = region
        self.population = population
        self.numberOfStoplights = stoplights
    }
    init?(population: Int, stoplights: Int) {
        self.init(region: "N/A", population: population, stoplights: stoplights)
    }
    
    func printTownDescription() {
        print("Population: \(population); number of stoplights: \(numberOfStoplights)")
    }
    
    mutating func changePopulation(amount: Int) {
        population += amount
    }
}
