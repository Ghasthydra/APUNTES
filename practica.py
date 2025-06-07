#la mision de todo esto es calcular el seno de X para un  
import numpy as np # se importa la libreria numpy para hacer rapidos calculos matematicos
import math # 

# Crear valores aleatorios  de inputs (valores asignados ala maquina para que lo procese) y output (resultado de la maquina)
x = np.linspace(-math.pi, math.pi, 2000)  #X es el output 
y = np.sin(x) #Y es el input 

# Pesos aleatorios de para (a,b,c,d)
a = np.random.randn()
b = np.random.randn()
c = np.random.randn()
d = np.random.randn()

learning_rate = 1e-6 #indice de aprendizaje del modelo tiene que ser un numero muy pequeño para que el modelo no se sobre ajuste
for t in range(2000): #2000 es el numero de iteraciones que se van a hacer para que el modelo se ajuste
    # Predecir los valores para Y
    # y = a + b x + c x^2 + d x^3
    y_pred = a + b * x + c * x ** 2 + d * x ** 3

    # Funcion de perdida (cuanto se aleja el resultado del modelo del resultado real)
    loss = np.square(y_pred - y).sum()
    if t % 100 == 99:
        print(t, loss)

    # Backprop to compute gradients of a, b, c, d with respect to loss
    grad_y_pred = 2.0 * (y_pred - y)
    grad_a = grad_y_pred.sum()
    grad_b = (grad_y_pred * x).sum()
    grad_c = (grad_y_pred * x ** 2).sum()
    grad_d = (grad_y_pred * x ** 3).sum() 
    #lo de arriba es el descenso del gradiente para que el modelo se ajuste a los datos


    # Pesos actualizados 
    a -= learning_rate * grad_a
    b -= learning_rate * grad_b
    c -= learning_rate * grad_c
    d -= learning_rate * grad_d

print(f'Result: y = {a} + {b} x + {c} x^2 + {d} x^3') #imprime todo el proceso ya mencionado 
