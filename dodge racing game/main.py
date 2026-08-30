import turtle as t
import random

# ---------------- SCREEN ---------------- #

screen = t.Screen()
screen.setup(width=700, height=700)
screen.bgcolor("black")
screen.title("🚀 Dodge the Meteors")
screen.tracer(0)


# ---------------- PLAYER ---------------- #

player = t.Turtle()
player.shape("triangle")
player.color("cyan")
player.penup()
player.goto(0, -280)
player.setheading(90)

player_speed = 30


# ---------------- SCORE ---------------- #

score = 0
lives = 3
game_over = False

score_display = t.Turtle()
score_display.hideturtle()
score_display.penup()
score_display.color("white")
score_display.goto(-320, 310)

score_display.write(
    f"Score: {score}    Lives: {'❤️ ' * lives}",
    font=("Arial", 18, "bold")
)


# ---------------- METEORS ---------------- #

meteors = []

for i in range(6):

    meteor = t.Turtle()
    meteor.shape("circle")
    meteor.color(random.choice(["red", "orange", "yellow", "white"]))
    meteor.penup()

    meteor.goto(
        random.randint(-320, 320),
        random.randint(100, 350)
    )

    meteors.append(meteor)


meteor_speed = 5


# ---------------- PLAYER MOVEMENT ---------------- #

def move_left():
    x = player.xcor()

    if x > -320:
        player.setx(x - player_speed)


def move_right():
    x = player.xcor()

    if x < 320:
        player.setx(x + player_speed)


screen.listen()

screen.onkeypress(move_left, "Left")
screen.onkeypress(move_right, "Right")


# ---------------- SCORE UPDATE ---------------- #

def update_score():

    score_display.clear()

    score_display.write(
        f"Score: {score}    Lives: {'❤️ ' * lives}",
        font=("Arial", 18, "bold")
    )


# ---------------- RESET METEOR ---------------- #

def reset_meteor(meteor):

    meteor.goto(
        random.randint(-320, 320),
        random.randint(350, 500)
    )

    meteor.color(
        random.choice([
            "red",
            "orange",
            "yellow",
            "white"
        ])
    )


# ---------------- GAME OVER ---------------- #

def show_game_over():

    message = t.Turtle()
    message.hideturtle()
    message.penup()
    message.color("white")
    message.goto(0, 0)

    message.write(
        "GAME OVER",
        align="center",
        font=("Arial", 35, "bold")
    )

    message.goto(0, -50)

    message.write(
        f"Final Score: {score}",
        align="center",
        font=("Arial", 20, "normal")
    )


# ---------------- GAME LOOP ---------------- #

def game_loop():

    global score
    global lives
    global meteor_speed
    global game_over

    if game_over:
        return

    # Move every meteor
    for meteor in meteors:

        meteor.sety(
            meteor.ycor() - meteor_speed
        )

        # Meteor reached bottom
        if meteor.ycor() < -330:

            reset_meteor(meteor)

            score += 1
            update_score()

        # Collision
        if meteor.distance(player) < 25:

            lives -= 1

            update_score()

            reset_meteor(meteor)

            if lives <= 0:

                game_over = True
                show_game_over()
                return

    # Increase difficulty
    if score > 0 and score % 10 == 0:
        meteor_speed = 5 + score // 10

    screen.update()

    screen.ontimer(game_loop, 30)


# ---------------- START GAME ---------------- #

game_loop()

screen.mainloop()
