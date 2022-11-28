#!/bin/sh
WIN_ID=`xdotool search --name 'PCB Editor'`
xdotool windowactivate $WIN_ID
sleep 1
xdotool windowactivate $WIN_ID
# FIND THE DESIRED KEY
xdotool key ctrl+f sleep 0.3 type H101
sleep 1
xdotool key Return
sleep 1
xdotool key Escape
sleep 2
# Activate edit mode
xdotool key e
sleep 3
xdotool key Tab sleep 0.3 key Tab
xdotool type 53.459999999999994
xdotool sleep 0.3 key Tab
xdotool type 177.704
xdotool sleep 0.3 key Return
sleep 1
# FIND THE DESIRED KEY
xdotool key ctrl+f sleep 0.3 type H102
sleep 1
xdotool key Return
sleep 1
xdotool key Escape
sleep 2
# Activate edit mode
xdotool key e
sleep 3
xdotool key Tab sleep 0.3 key Tab
xdotool type 401.59749999999997
xdotool sleep 0.3 key Tab
xdotool type 177.704
xdotool sleep 0.3 key Return
sleep 1
# FIND THE DESIRED KEY
xdotool key ctrl+f sleep 0.3 type H103
sleep 1
xdotool key Return
sleep 1
xdotool key Escape
sleep 2
# Activate edit mode
xdotool key e
sleep 3
xdotool key Tab sleep 0.3 key Tab
xdotool type 401.59749999999997
xdotool sleep 0.3 key Tab
xdotool type 311.654
xdotool sleep 0.3 key Return
sleep 1
# FIND THE DESIRED KEY
xdotool key ctrl+f sleep 0.3 type H104
sleep 1
xdotool key Return
sleep 1
xdotool key Escape
sleep 2
# Activate edit mode
xdotool key e
sleep 3
xdotool key Tab sleep 0.3 key Tab
xdotool type 53.459999999999994
xdotool sleep 0.3 key Tab
xdotool type 311.654
xdotool sleep 0.3 key Return
sleep 1
xdotool key alt+p
sleep 1
xdotool key Down
xdotool key Down
xdotool key Down
xdotool key Down
xdotool key Down
xdotool key Down
xdotool key Down
xdotool key Down
xdotool key Return
sleep 1
xdotool key Return
sleep 1
xdotool key e
sleep 1
xdotool type 48.459999999999994
xdotool key Tab
xdotool type 172.704
xdotool key Tab
xdotool type 406.59749999999997
xdotool key Tab
xdotool type 316.654
xdotool key Tab
xdotool key Tab
xdotool key Tab
xdotool key Tab
xdotool key Tab
sleep 1
xdotool key Up
xdotool key Up
xdotool key Up
xdotool key Up
xdotool key Up
xdotool key Up
xdotool key Up
xdotool key Up
xdotool key Up
xdotool key Up
xdotool key Up
xdotool key Up
xdotool key Up
xdotool key Up
xdotool key Up
xdotool key Up
xdotool key Up
xdotool key Up
xdotool key Up
xdotool key Up
sleep 1
xdotool key Down
xdotool key Down
xdotool key Down
xdotool key Down
xdotool key Down
xdotool key Down
xdotool key Down
xdotool key Down
xdotool key Down
xdotool key Down
xdotool key Down
xdotool key Down
xdotool key Down
xdotool key Down
sleep 1
sleep 1
xdotool key Tab
sleep 1
xdotool key Return
sleep 1
xdotool key ctrl+shift+t
sleep 1
xdotool key Escape
sleep 1
espeak 'Layout complete.'