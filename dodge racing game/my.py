import turtle as t 
import random

screen = t.Screen()

screen.setup(width=700, height=700)
screen.bgcolor("black")
screen.title("dodge the Meteors")


def move_left():
    current_x = player.xcor()
    new_x = current_x - movement_amount
    player.setx(new_x)
     
     mukan mkahija 
    
def move_right():
    current_x = player.xcor()
    new_x = current_x + movement_amount
    player.setx(new_x)


meteor = t.Turtle()
meteor.shape("circle")
meteor.color("red")
meteor.penup()
meteor.speed("fastest")

meteor.goto(random.randint(-330,330),300)
       
def create_meteor():
    current_y = meteor.ycor()
    new_y = current_y - movement_amount
    meteor.sety(new_y)
  
    
    
    
    
screen.listen()
screen.onkey(move_left,"left")
screen.onkey(move_right,"right")





screen.mainloop()




