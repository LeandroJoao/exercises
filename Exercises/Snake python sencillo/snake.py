import pygame, sys, time, random

pygame.init()

play_surface = pygame.display.set_mode((500, 500)) #Variable que contiene la pantalla (ancho y alto)

fps = pygame.time.Clock() #Los frames por segundo

font = pygame.font.Font(None, 30) #Fuente para el score

def food():
    random_pos = random.randint(0, 49)*10
    food_pos = [random_pos, random_pos]

    return food_pos

        

def main():
                # x   y
    snake_pos = [100, 50] #Cabeza de la serpiente [píxeles donde se situa la serpiente dentro de la pantalla (500, 500)]
    snake_body = [[100, 50], [90, 50], [80, 50]] #Cuerpo de la serpiente

    change = "RIGHT" #tecla presionada (predeterminado que vaya a la derecha)
    run = True
    food_pos = food()
    score = 0

    while run:

        for event in pygame.event.get(): #obtiene eventos dentro de la pantalla
            if event.type == pygame.QUIT: #En caso de darle a la X se cierra
                run = False #Si se da a la X run cambia a false y se cierra
            if event.type == pygame.KEYDOWN:#Si el evento es presionar
                if event.key == pygame.K_RIGHT: #Si se presiona la flecha a la derecha
                    change = "RIGHT"
                if event.key == pygame.K_LEFT: #Si se presiona la flecha a la izquierda
                    change = "LEFT"
                if event.key == pygame.K_UP: #Si se presiona la flecha hacia arriba
                    change = "UP"
                if event.key == pygame.K_DOWN: #Si se presiona la flecha hacia abajo
                    change = "DOWN"
                if event.key == pygame.K_ESCAPE:
                    run = False
        #Movimiento de la serpiente            
        if change == "RIGHT":
            snake_pos[0] += 10 #0 ya que es movimiento en x
        if change == "LEFT":
            snake_pos[0] -= 10
        if change == "UP":
            snake_pos[1] -= 10 #1 ya que es movimiento en y
        if change == "DOWN":
            snake_pos[1] += 10



        snake_body.insert(0, list(snake_pos))  #Se añade la posicion snake pos a snakebody
        
        if snake_pos == food_pos: #si la posición de la serpiente está en el mismo sitio de la pos food 
            food_pos = food() #Se cambia la posicion a otro lado
            score += 1  #Se suma un punto en el score
            print(score)
        else:        #de lo contrario se eliminará la parte de atrás
            snake_body.pop() #Se va a eliminar la posicion anterior pop ya que se desea eliminar la ultima pos añadida

        play_surface.fill((0,0,0)) #Color de fondo (Negro es 0,0,0)

        for pos in snake_body: #lugar()pantalla  #color             #rectangulo en 100, 50      10 pixeles de ancho y alto
            pygame.draw.rect(play_surface, (0,255,0), pygame.Rect(pos[0], pos[1], 10, 10))
            pygame.draw.rect(play_surface, (169, 6, 6), pygame.Rect(food_pos[0], food_pos[1], 10, 10))
        
        text = font.render(str(score), 0, (200, 60, 80))
        play_surface.blit(text, (480, 20)) #El texto de arriba y la posicion donde estará

        if score < 10: #Niveles
            fps.tick(10)
        if score >= 10:
            fps.tick(20)

        if snake_pos[0] <= 0:
            snake_pos[0] = 500
        elif snake_pos[0] >= 500:
            snake_pos[0] = 0

        if snake_pos[1] <= 0:
            snake_pos[1] = 500
        elif snake_pos[1] >= 500:
            snake_pos[1] = 0
            #run = False
            #print("YOU LOSE")
        
        pygame.display.flip() #Actualiza todo lo que hemos hecho



main()

pygame.quit()

