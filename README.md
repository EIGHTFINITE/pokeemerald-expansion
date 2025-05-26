# pokeemerald-expansion

You're probably looking for:

https://github.com/EIGHTFINITE/pokeemerald-expansion/tree/master  
https://github.com/EIGHTFINITE/pokeemerald-expansion/blob/master/INSTALL.md  
https://github.com/EIGHTFINITE/pokeemerald-expansion/blob/master/CHANGELOG.md

Or if you want to start coding:

```
git init .
git remote add origin https://github.com/EIGHTFINITE/pokeemerald-expansion.git
git remote add RHH https://github.com/rh-hideout/pokeemerald-expansion.git
git remote add pret https://github.com/pret/pokeemerald.git
git remote add merrp https://github.com/aarant/pokeemerald.git
git remote add team_aqua https://github.com/TeamAquasHideout/pokeemerald.git
git fetch --force --all --tags
git update-index --no-assume-unchanged "src/data/battle_partners.h"
git update-index --no-assume-unchanged "src/data/pokemon/teachable_learnsets.h"
git reset --hard refs/remotes/origin/master
git checkout -B master refs/remotes/origin/master
git update-index --assume-unchanged "src/data/battle_partners.h"
git update-index --assume-unchanged "src/data/pokemon/teachable_learnsets.h"

```
