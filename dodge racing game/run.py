import turtle as t
import random

# ---------------- SCREEN ---------------- #

screen = t.Screen()
screen.setup(width=700, height=700)
screen.bgcolor("black")
screen.title("Dodge the Meteors")
screen.tracer(0)


# ---------------- PLAYER ---------------- #

player = t.Turtle()
player.shape("triangle")
player.color("cyan")
player.penup()
player.goto(0, -280)
player.setheading(90)

player_speed = 30


# ---------------- GAME VARIABLES ---------------- #

score = 0
lives = 3
game_over = False

meteor_count = 6
meteor_speed = 5

meteors = []


# ---------------- SCORE ---------------- #

score_display = t.Turtle()
score_display.hideturtle()
score_display.penup()
score_display.color("white")
score_display.goto(-320, 310)


def update_score():

    score_display.clear()

    score_display.write(
        f"Score: {score}    Lives: {lives}",
        font=("Arial", 18, "bold")
    )


# ---------------- DIFFICULTY ---------------- #

def choose_difficulty():

    global meteor_count
    global meteor_speed

    while True:

        difficulty = screen.textinput(
            "Difficulty",
            "Choose:\nEasy\nMedium\nHard"
        )

        if difficulty is None:
            return False

        difficulty = difficulty.lower().strip()

        if difficulty == "easy":

            meteor_count = 4
            meteor_speed = 3
            return True

        elif difficulty == "medium":

            meteor_count = 6
            meteor_speed = 5
            return True

        elif difficulty == "hard":

            meteor_count = 10
            meteor_speed = 8
            return True

        else:

            screen.textinput(
                "Invalid Choice",
                "Please enter Easy, Medium, or Hard."
            )


# ---------------- METEORS ---------------- #

def create_meteors():

    for meteor in meteors:
        meteor.hideturtle()

    meteors.clear()

    for i in range(meteor_count):

        meteor = t.Turtle()

        meteor.shape("circle")

        meteor.color(
            random.choice(
                ["red", "orange", "yellow", "white"]
            )
        )

        meteor.penup()
        meteor.speed("fastest")

        meteor.goto(
            random.randint(-320, 320),
            random.randint(100, 500)
        )

        meteors.append(meteor)


def reset_meteor(meteor):

    meteor.goto(
        random.randint(-320, 320),
        random.randint(350, 500)
    )

    meteor.color(
        random.choice(
            ["red", "orange", "yellow", "white"]
        )
    )


# ---------------- PLAYER MOVEMENT ---------------- #

def move_left():

    if not game_over:

        x = player.xcor()

        if x > -320:

            player.setx(x - player_speed)

            screen.update()


def move_right():

    if not game_over:

        x = player.xcor()

        if x < 320:

            player.setx(x + player_speed)

            screen.update()


# ---------------- KEYBOARD ---------------- #

def setup_keyboard():

    screen.listen()

    screen.onkey(move_left, "Left")
    screen.onkey(move_right, "Right")

    # Make sure the Turtle window gets keyboard focus
    screen.getcanvas().focus_force()


# ---------------- GAME OVER ---------------- #

def show_game_over():

    message = t.Turtle()

    message.hideturtle()
    message.penup()
    message.color("white")

    message.goto(0, 60)

    message.write(
        "GAME OVER",
        align="center",
        font=("Arial", 35, "bold")
    )

    message.goto(0, 10)

    message.write(
        f"Final Score: {score}",
        align="center",
        font=("Arial", 20, "normal")
    )

    return message


# ---------------- RESET GAME ---------------- #

def reset_game():

    global score
    global lives
    global game_over

    score = 0
    lives = 3
    game_over = False

    player.goto(0, -280)

    update_score()

    create_meteors()

    setup_keyboard()


# ---------------- PLAY AGAIN ---------------- #

def play_again(message):

    answer = screen.textinput(
        "Play Again?",
        "Do you want to play again?\nYes / No"
    )

    if answer is not None and answer.lower().strip() == "yes":

        message.clear()

        if choose_difficulty():

            reset_game()
            game_loop()

        else:

            message.goto(0, -40)

            message.write(
                f"Final Score: {score}",
                align="center",
                font=("Arial", 20, "normal")
            )

    else:

        message.goto(0, -40)

        message.write(
            f"Final Score: {score}",
            align="center",
            font=("Arial", 20, "normal")
        )

        message.goto(0, -80)

        message.write(
            "Thanks for playing!",
            align="center",
            font=("Arial", 18, "normal")
        )

    screen.update()


# ---------------- GAME LOOP ---------------- #

def game_loop():

    global score
    global lives
    global game_over

    if game_over:
        return

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

                message = show_game_over()

                screen.update()

                play_again(message)

                return

    screen.update()

    screen.ontimer(game_loop, 30)


# ---------------- START GAME ---------------- #

if choose_difficulty():

    update_score()

    create_meteors()

    setup_keyboard()

    game_loop()

    screen.mainloop()

else:

    screen.bye()