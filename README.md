# Revive System Alpha

[![Version](https://img.shields.io/github/release/HelionGaming/Revive-System.svg?label=Version&colorB=007EC6&style=flat-square)](https://github.com/HelionGaming/Revive-System/releases/latest)
[![Issues](https://img.shields.io/github/issues-raw/HelionGaming/Revive-System.svg?label=Issues&style=flat-square)](https://github.com/HelionGaming/Revive-System/issues)
[![License](https://img.shields.io/badge/License-APL--SA-orange.svg?style=flat-square)](https://github.com/HelionGaming/Revive-System/blob/master/LICENSE.md)

This is a rudimentary but working Revive System for Arma Reforger. The code for this was entirely assembled by ChatGPT, first of it's kind for Reforger I think. However ChatGPT can only take you 90% there with no coding knowledge, That's why I wanna thank Bacon#8008 and Zelik#0033 for assisting me when I hit a rut.

## Features

- Unconscious Players don't die until their 5 min timer runs out
- Players can revive eachother using a bandage
- Reviving adds back health and blood to the player
- Explosions don't (usually) kill players, instead it sends them away ragdoll-style
- Better Squad Cohesion, by making players stick together and lessens the chance of being sent back to spawn and losing coms range with with your squad.
- It's more fun 


## Caveats

- Players can still die depending on the damage they take, but for the most part the chance of going unconscious is roughly 70% based on my testing. The way this is achieved is by editing the character base to reduce incoming damage. This is not a great way to do it, but it works for now.
- Players drop their weapons when in a downed state, and will need to pick them up again, they can also be deleted by GM if they do an entity purge before players have picked up their weapons, might not be possible to fix.
- Revive is a bit too quick, I'd like it to only actually revive after the animations is finished, will work on this
- Players die inside vehicles on purpose due to issues with the ragdoll physics. I will work on making it so they player is ejected first then made unconscious.
- GMs can no longer heal players, don't know why this is, still trying to figure this one out.
- GM controlled AI will act as a player and go unconscious. Not gonna remove this since it can be used for roleplay purposes. Will see if it's possible to make them not invincible.

## References

### Workshop Link

https://reforger.armaplatform.com/workshop/5C4F718AD8469951-ReviveSystemAlpha

### Mods JSON

```json
"mods": [
    {
        "modId": "5C4F718AD8469951",
        "name": "Revive System Alpha"
    }
]
```

### Mission Header Parameters

_TBD_

## Submitting Issues

Please use our [Issue Tracker](https://github.com/HelionGaming/Revive-System/issues/new/choose) to report a bug, propose a feature, or suggest changes to the existing ones.

## License
This mod is licensed under the Arma Public License Share Alike ([APL-SA](https://github.com/HelionGaming/Revive-System/blob/main/LICENSE.md)).


