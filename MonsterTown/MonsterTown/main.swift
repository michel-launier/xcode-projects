//
//  main.swift
//  MonsterTown
//
//  Created by Michel Launier on 2021-01-30.
//

import Foundation

var myTown = Town(population: 10000, stoplights: 6)
myTown?.printTownDescription()

var fredTheZombie: Zombie? = Zombie(limp: true, fallingAppart: false, town: myTown, name: "Fred the zombie")
fredTheZombie?.terrorizeTown()
fredTheZombie?.town?.printTownDescription()
myTown?.printTownDescription()

print("Victim pool: \(String(describing: fredTheZombie?.victimPool))")
fredTheZombie?.victimPool = 500
print("Victim pool: \(fredTheZombie?.victimPool ?? 0)")
print(Zombie.spookyNoise)
if Zombie.isTerrifying {
    print("Run away")
}
fredTheZombie = nil
