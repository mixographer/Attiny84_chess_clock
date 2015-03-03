# Attiny84 Chess Clock
A chess clock based on the Atmel Attiny84 micorcontroller.

This project is a simple chess clock based on the Atmel Attiny84 micoprocessor. It uses the SCD55104 LED Display 
module to display player times and user interface menus. The time periods are adjustable and the clock operated 
in three different modes. 

# Modes
## Sudden Death
In Sudden-death mode, your clock runs when it is your turn, and you lose when you run out of time. 

## Fischer Delay
In Fischer Delay mode, an increment is added at the start of each turn. In Fischer Increment mode you can actually 
add time to your total if you move faster than the increment amount. 

## Hourglass
In Hourglass mode, as one player's time goes down, the other player's time goes up. 

# Operation 
The Chess Clock has four buttons that are used during gameplay, and to set the parameters of the clock. 
1. Start/Reset
2. Player 1/Down
3. Player 2/Up
4. Pause/Enter

## Start
To begin using the clock press the Start/Reset button. 

## Set Time
You will be prompted to set the time period for the game with the text "Set Time:" Use the 'Player 1/Down' and 'Player 2/Up' buttons to set the time period. The default time is 2 minutes. The 'down' button reduces the time period while the 'up' button adds time. If the current time setting is 1:00 the down button will reduce the time period by 50%. The 'up' button adds 1 minute to the time period. 

When you have set the desired time period with the 'down' and 'up' buttons, press the 'Pause/Enter' button to accept the time period. 

## Set Mode
You will be prompted to set the mode of the clock.

#### Sudden Death
The default mode is Sudden Death or Guillotine. If you would like this mode simply hit the "Pause/Enter" button. 
The time period will be displayed for both players, and a play can begin. 

#### Fischer Delay
Fischer delay mode can be selected by pressing the 'Player 1/Down' button at the 'Set Mode' prompt. 'Fischer' is displayed on the clock and you can accept Fischer delay mode by pressing the 'Pause/Enter' button. 

Set the increment. 
In Fischer delay mode, an increment period is required. The clock will prompt for the increment with the display "Inc?: 0:05." Set the desired increment with the 'Player 1/Down' and 'Player 2/Up' buttons. The increment adjusts in 1 second increments. Accept the increment with the 'Pause/Enter' button, the time period will be displayed and play can begin.

#### Hourglass
Hourglass mode can be selected by pressing the 'Player2/Up' button at the 'Set Mode' prompt. Hourglass mode operates like an hourglass. As time is decreasing for one player, it is increasing for the other player. Press the 'Pause/Enter' button and play can begin. 

## Play
Once the time period and mode have been set, the clock is ready to use. If during play, the clock needs to be paused for any reason, the 'Pause/Enter' will stop the clock at the current time. Play may be restarted by pressing either the 'Player1' or 'Player 2' button.

###Keywords
Chess Clock, DIY Chess Clock, Atmel, Attiny, Blitz, Bullet, Chess.

- - - 
### License
Licensed under the MIT License. See LICENSE.txt. 
