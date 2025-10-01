# Unreal_TD_1

Controls:

Z Q S D    -> Player Movement
Left Shift -> Player Dash
Space      -> Player Jump
X          -> Test Debug Damage (take 1 damage)

Inputs are disabled on win and death (+ trigger ragdoll state)


Trap Types:

- Spike Trap      -> Overlap (1 damage)
- Lava            -> Overlap (insta-death)
- Spike Ball      -> Hit (1 damage, but can insta-death if multi-hit)
- Trick Platform  -> Green and Blue platform; stepping on the blue one trigger the trap, and you fall in lava
- Moving Platform -> 2 simple platforms that moves on the X-axis with Spike Balls and lava below


UI Types:

- Health UI -> Display {CurrentHealth / MaxHealth} in the top left corner
- Death UI  -> Displayed on death
- Win UI    -> Displayed on reaching the goal


Collectibles:

- Health container -> 2 health containers in the middle that restore 1 health
