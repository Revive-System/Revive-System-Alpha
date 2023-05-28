# Revive System Alpha

[![Version](https://img.shields.io/github/release/HelionGaming/Revive-System.svg?label=Version&colorB=007EC6&style=flat-square)](https://github.com/HelionGaming/Revive-System/releases/latest)
[![Issues](https://img.shields.io/github/issues-raw/HelionGaming/Revive-System.svg?label=Issues&style=flat-square)](https://github.com/HelionGaming/Revive-System/issues)
[![License](https://img.shields.io/badge/License-APL--SA-orange.svg?style=flat-square)](https://github.com/HelionGaming/Revive-System/blob/master/LICENSE.md)

> This is a rudimentary but working Revive System for Arma Reforger. The code for this was entirely assembled by ChatGPT, first of it's kind for Reforger I think. 
> However ChatGPT can only take you 90% there with no coding knowledge, That's why I wanna thank Bacon#8008 and Zelik#0033 for assisting me when I hit a rut.
>
> -- [Helion](https://github.com/HelionGaming)

## Features

- Unconscious players will die when they bleed out. The more open wounds they have, the faster they will bleed out (Bleeding rate can be configured with `"m_fBleedingRate"`)
- Players can revive eachother by treating all bleeding wounds with bandages
- Reviving adds back health and blood to the player
- Explosions don't kill players, instead it sends them away ragdoll-style
- Better Squad Cohesion, by making players stick together and lessens the chance of being sent back to spawn and losing coms range with with your squad.
- It's more fun 


## Caveats

- Currently only critical injured players become unconsciousness, which means that mildely injured players will bleed out without falling unconscious first.
- Players drop their weapons when in a downed state, and will need to pick them up again, they can also be deleted by GM if they do an entity purge before players have picked up their weapons, might not be possible to fix.
- Players die inside vehicles on purpose due to issues with the ragdoll physics. I will work on making it so they player is ejected first then made unconscious.
- GMs can no longer heal players, don't know why this is, still trying to figure this one out.
- GM controlled AI will act as a player and go unconscious. Not gonna remove this since it can be used for roleplay purposes. Will see if it's possible to make them not invincible.

## References

### Workshop Link

https://reforger.armaplatform.com/workshop/6FD4307E24115E90-ReviveSystemAlpha

### Mods JSON

```json
"mods": [
    {
        "modId": "6FD4307E24115E90",
        "name": "Revive System Alpha"
    }
]
```

### Mission Header Parameters

- Bleeding rate multiplier (default: `0.56`): `"m_fBleedingRate"`
- Health and blood level regeneration rate multiplier (default: `1.00`): `"m_fHealthAndBloodRegenerationRate"`

## Contributing

You can help out with the ongoing development by looking for potential bugs in our code base, or by contributing new features. We are always welcoming new [pull requests](https://github.com/Revive-System/Revive-System-Alpha/pulls) containing bug fixes, refactors and new features. We have a list of tasks and bugs on our issue tracker on GitHub. Please comment on issues you want to contribute with, to avoid duplicating effort.

To contribute something to this mod, simply fork this repository and submit your pull requests for review by other collaborators. Feel free to contact us if you need help getting started with GitHub.

## Submitting Issues

Please use our [Issue Tracker](https://github.com/HelionGaming/Revive-System/issues/new/choose) to report a bug, propose a feature, or suggest changes to the existing ones.

## License
This mod is licensed under the Arma Public License Share Alike ([APL-SA](https://github.com/HelionGaming/Revive-System/blob/main/LICENSE.md)).


