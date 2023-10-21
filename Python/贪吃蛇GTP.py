# 导入必要的模块
import pygame
import random

# 初始化pygame
pygame.init()

# 定义颜色
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
RED = (255, 0, 0)
GREEN = (0, 255, 0)
BLUE = (0, 0, 255)

# 设置屏幕大小
SCREEN_WIDTH = 800
SCREEN_HEIGHT = 600
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))

# 设置游戏标题
pygame.display.set_caption("贪吃蛇游戏")

# 设置游戏时钟
clock = pygame.time.Clock()

# 定义蛇的初始位置和大小
snake_block_size = 10
snake_speed = 15
font_style = pygame.font.SysFont(None, 30)

# 定义显示分数的函数
def show_score(score):
    score_font = font_style.render("Score: " + str(score), True, BLUE)
    screen.blit(score_font, [0, 0])

# 定义画蛇的函数
def draw_snake(snake_block_size, snake_list):
    for x in snake_list:
        pygame.draw.rect(screen, GREEN, [x[0], x[1], snake_block_size, snake_block_size])

# 定义主函数
def gameLoop():
    game_over = False
    game_close = False

    # 定义蛇的初始位置和长度
    x1 = SCREEN_WIDTH / 2
    y1 = SCREEN_HEIGHT / 2
    x1_change = 0
    y1_change = 0
    snake_List = []
    Length_of_snake = 1

    # 定义食物的初始位置
    foodx = round(random.randrange(0, SCREEN_WIDTH - snake_block_size) / 10.0) * 10.0
    foody = round(random.randrange(0, SCREEN_HEIGHT - snake_block_size) / 10.0) * 10.0

    # 开始游戏循环
    while not game_over:

        # 如果游戏结束，显示游戏结束信息
        while game_close == True:
            screen.fill(WHITE)
            message = font_style.render("You Lost! Press Q-Quit or C-Play Again", True, RED)
            screen.blit(message, [SCREEN_WIDTH / 6, SCREEN_HEIGHT / 3])
            show_score(Length_of_snake - 1)
            pygame.display.update()

            # 等待用户选择
            for event in pygame.event.get():
                if event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_q:
                        game_over = True
                        game_close = False
                    if event.key == pygame.K_c:
                        gameLoop()

        # 处理用户输入
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                game_over = True
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_LEFT:
                    x1_change = -snake_block_size
                    y1_change = 0
                elif event.key == pygame.K_RIGHT:
                    x1_change = snake_block_size
                    y1_change = 0
                elif event.key == pygame.K_UP:
                    y1_change = -snake_block_size
                    x1_change = 0
                elif event.key == pygame.K_DOWN:
                    y1_change = snake_block_size
                    x1_change = 0

        # 判断蛇是否撞到墙壁
        if x1 >= SCREEN_WIDTH or x1 < 0 or y1 >= SCREEN_HEIGHT or y1 < 0:
            game_close = True

        # 更新蛇的位置
        x1 += x1_change
        y1 += y1_change

        # 绘制游戏背景
        screen.fill(WHITE)

        # 绘制食物
        pygame.draw.rect(screen, RED, [foodx, foody, snake_block_size, snake_block_size])

        # 更新蛇的长度
        snake_Head = []
        snake_Head.append(x1)
        snake_Head.append(y1)
        snake_List.append(snake_Head)
        if len(snake_List) > Length_of_snake:
            del snake_List[0]

        # 判断蛇是否吃到食物
        for x in snake_List[:-1]:
            if x == snake_Head:
                game_close = True

        # 绘制蛇
        draw_snake(snake_block_size, snake_List)
        show_score(Length_of_snake - 1)
        pygame.display.update()

        # 判断蛇是否吃到食物
        if x1 == foodx and y1 == foody:
            foodx = round(random.randrange(0, SCREEN_WIDTH - snake_block_size) / 10.0) * 10.0
            foody = round(random.randrange(0, SCREEN_HEIGHT - snake_block_size) / 10.0) * 10.0
            Length_of_snake += 1

        # 设置游戏速度
        clock.tick(snake_speed)

    # 退出pygame
    pygame.quit()

# 开始游戏
gameLoop()
