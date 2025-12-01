/*
Declaración y diseño de funciones:
Responsabilidad única: una función debe hacer una sola cosa bien.
Nombres claros: verbos en camelCase, PascalCase o snake_case consistente con tu código base.
*/

/*
1. Usa el verbo imperativo (Añadir, Cambiar, Arreglar, Remover, …)
Aunque el mensaje puede sonar un poco raro el verbo presente es una forma de expresar la acción que se realiza en el commit. 
Por ejemplo, Añadir significa que se añade un nuevo archivo, Cambiar significa que se modifica un archivo existente y 
Arreglar significa que se arregla un bug.

Sé que muchas veces estamos tentados a escribirlo en pasado “Añadido…”, “Arreglado…” o “Removido…” pero cada commit hay que entenderlo como una instrucción para cambiar el estado del proyecto. Dicho de otro modo, el verbo presente nos permite saber qué estado queremos que el proyecto se encuentre en el momento de añadir el commit.

Sólo hay que ver también los mensajes de commit que el propio Git nos añade (al hacer merge de una rama usa Merge branch).
*/

/*  
2. No uses punto final ni puntos suspensivos en tus mensajes
Usar puntuación, más allá de las comas, es innecesario a la hora de crear un buen mensaje de commit. Cada carácter cuenta a la hora de crear un buen mensaje de commit así que no lo desperdicies con puntos innecesarios.

¿Por qué? El primer mensaje de commit es el título del commit. Y según las reglas de puntuación para títulos, tanto en castellano como en inglés, estos no llevan puntuación final. Sobre los puntos suspensivos… ¡Nuestros commits no deberían tener ningún suspenso! Deben ser una instrucción clara y concisa.
*/

/*  
3. Usa como máximo 50 carácteres para tu mensaje de commit
Sé corto y conciso. Si tienes mucho que explicar… seguramente es que tu commit hace demasiadas cosas. ¿Puedes separarlo en diferentes commits? Pues hazlo.

Haz que el mensaje sea claro, directo y que realmente refleje los cambios que lleva.
*/

/*  
4. Usa un prefijo para tus commits para hacerlos más semánticos
Cuando un proyecto crece, es necesario que existan ciertas reglas para que el historial sea legible. Para ello, puedes añadir un prefijo para darle más significado a los commits que realizas. A esto se le llama commits semánticos y se haría de la siguiente manera:
Puedes usar los siguientes prefijos

feat: Una nueva característica para el usuario.
fix: Arregla un bug que afecta al usuario.
perf: Cambios que mejoran el rendimiento del sitio.
build: Cambios en el sistema de build, tareas de despliegue o instalación.
ci: Cambios en la integración continua.
docs: Cambios en la documentación.
refactor: Refactorización del código como cambios de nombre de variables o funciones.
style: Cambios de formato, tabulaciones, espacios o puntos y coma, etc; no afectan al usuario.
test: Añade tests o refactoriza uno existente.
En su defecto tambien puedes usar emojis para indicar el tipo de commit que se esta haciendo, por ejemplo usando la herramienta Gitmoji, donde cada emoji tiene su propia razon de ser es decir, no debemos poner el emoji que mejor nos parezca, si no el que este acorde al commit, puedes revisarlo en la siguiente web.
*/

//solo se permiten estas librerias no usar otras, no usarlas todas solo las necesarias
#include <iostream>
#include <queue>
#include<stack>
#include <list>
#include <algorithm>
#include <string>
#include <map>
#include <limits>
#include <vector>
#include <set>
#include <sstream>
#include<unordered_set>
#include<unordered_map>

//git status	Te dice en qué rama estás y el estado de tus archivos.
//git branch	Lista todas las ramas que tienes. La rama actual tiene un asterisco (*).
//git log --oneline --graph	Muestra el historial de commits de una forma gráfica, útil para ver las ramas.
//git branch <nombre-de-rama>	Crea una nueva rama, por ejemplo: git branch nueva-funcion.
//git checkout <nombre-de-rama>	Te mueve a esa rama. Ahora, cualquier cambio que hagas será en esa rama.
//git checkout -b <nombre-de-rama>	El comando más usado: Crea la rama Y te mueve a ella en un solo paso.
//git switch <nombre-de-rama>	Alternativa moderna a checkout para solo cambiar de rama (más clara).
//git switch -c <nombre-de-rama>	Alternativa moderna a checkout -b para crear y cambiar.
//git merge <nombre-de-rama>	Combina la rama especificada en la rama actual.
//git branch -d <nombre-de-rama>	Elimina la rama localmente. Solo funciona si la rama ya ha sido fusionada.
//git branch -D <nombre-de-rama>	Fuerza la eliminación. Úsalo si quieres eliminar la rama antes de fusionarla (ten cuidado, ¡se pierden los cambios!).