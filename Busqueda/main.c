#include <stdio.h>
#include <stdlib.h>
/**
 * Que me dice que me quiere
Que vivir sin mí no puede
Que lo agobian los momentos en que no estoy junto a él
Que siempre me había esperado
Que era a quien había soñado
La que su mamá quería pa' que fuera su mujer
Que mis ojos son estrellas
Que mi risa es la más bella
Que todos mis atributos son perfectos para él
Que si fuera un retratista
Que si fuera un buen artista
Yo sería su Mona Lisa y hasta un tango de Gardel
Y a él solo lo trago yo
Quiero que tú sepas que tú no eres para mí
Que tú no eres para mí, siempre supe pero no hice caso
Que ni se te ocurra aparecer por aquí
Aparecer por aquí
Con tus enredos y cuentos baratos
Quiero que tú sepas que yo no soy para ti
Que no yo soy para ti, siempre supe pero no hice caso
Que ni se me ocurra estar de nuevo junto a ti
Estar de nuevo junto a ti
Mi corazón no aguanta más fracaso
Que me promete la luna
Que yo soy como ninguna
Que parezco una doncella de esas que hay que proteger
Que sus vicios ha dejado
Que su suelo le ha aumentado
Que me promete la vida que yo siento merecer
Y hoy solo lo trago yo
Quiero que tú sepas que tú no eres para mí
Que tú no eres para mí, siempre supe pero no hice caso
Que ni se te ocurra aparecer por aquí
Aparecer por aquí
Con tus enredos y cuentos baratos
Quiero que tú sepas que yo no soy para ti
Que no yo soy para ti, siempre supe pero no hice caso
Que ni se me ocurra estar de nuevo junto a ti
Estar de nuevo junto a ti
Mi corazón no aguanta más fracaso
Y yo que tanto me decía que no me convenías
Que eras mi destrucción
Y siempre yo tratando de dejarte
Tu día ya llego
Tu día ya llego
Quiero que tú sepas que tú no eres para mí
Que tú no eres para mí, siempre supe pero no hice caso
Que ni se te ocurra aparecer por aquí
Aparecer por aquí
Con tus enredos y cuentos baratos
Quiero que tú sepas que yo no soy para ti
Que no yo soy para ti, siempre supe pero no hice caso
Que ni se me ocurra estar de nuevo junto a ti
Estar de nuevo junto a ti
Mi corazón no aguanta más fracaso
*/
int busquedaBinaria( int arr[], int v, int i, int j ) {
    int k = ( i + j ) / 2;
    // Condicion de corte
    if( i >= j ) return -i;

    if( arr[k] == v ) return k;
    else {
        if( arr[k] < v ) i = k+1;
        else j = k-1;

        // Invocación recursiva osi osi
        return busquedaBinaria( arr, v , i, j );
    } 
}
int main() {
    int arreglo[] = { 2, 4, 5, 8, 12, 18, 23, 45 };
    int v = 6;

    printf("%d", busquedaBinaria(arreglo, v , 0, 7 ));
}