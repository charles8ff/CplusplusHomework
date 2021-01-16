  
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <algorithm>

using namespace std;
float laMedia(vector<int>const&laRistra){
    float sum{0.00},media{0.00};
    for (auto i:laRistra){
        sum=sum+i;
    }
    media=sum/laRistra.size();
    return media;
}
float laDesTip(vector<int>const&laRistra){
    float media=laMedia(laRistra);
    float sumato{0.00};
    for(auto elem:laRistra){
        sumato +=(elem-media)*(elem-media);
    }
    sumato=sumato/laRistra.size();
    return sqrt(sumato);
}
float laMediana(vector<int>laRistra){
    sort(laRistra.begin(),laRistra.end());
    int index=laRistra.size()/2;
    if(laRistra.size()%2==0){
        return laRistra[index-1];
    }
    else return ((laRistra[index]+laRistra[index+1])/2.00);
}
vector<int> genLaRistra(int rng, int top,int bot){
    vector<int>laRistra;
    for (int i=0;i<rng;i++){
       laRistra.push_back(rand() % top + bot);
    }
    return laRistra;
}
int main()
{
    //Parameters;
    int rng{0},top{0},bot{0},choose{0};
    float printf{0.00};
    vector<int>laRistra;
    srand(time(NULL));
    cout << "Introduzca la cantidad de numeros aleatorios que desea.\n >>";
    cin >> rng;
    cout << "Inroduzca un limite inferior y superior para acotar los numeros generados.\n >>";
    cin >> bot >> top;
    laRistra=genLaRistra(rng,top,bot);

    for(auto elem:laRistra){
        cout << elem << " - ";
    }

    //menu
    do{
        cout << "\nQue desea hacer con esta semejante ristra de numeros? Elija una opcion\n"
                "1. Calcular la media:\n"
                "2. Calcular la desviacion tipica:\n"
                "3. Calcular la mediana:\n"
                "4. Crear una nueva ristra:\n";
                "5. Cerrar:\n";
        cin >> choose;
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore();
            choose = 7;
        }
        switch (choose) {
        case 1:
            std::cin.clear();
            std::cin.ignore();
            printf=laMedia(laRistra);
            cout << "La media de tu ristra es "<<printf<<".\n\n";

            break;
        case 2:
            std::cin.clear();
            std::cin.ignore();
            printf=laDesTip(laRistra);
            cout << "La esto de tu ristra es "<<printf<<".\n\n";
            break;
        case 3:
            std::cin.clear();
            std::cin.ignore();
            printf=laMediana(laRistra);
            cout << "La mediana de tu ristra es "<<printf<<".\n\n";
            break;
        case 4:
            std::cin.clear();
            std::cin.ignore();
            cout << "Introduzca la cantidad de numeros aleatorios que desea.\n >>";
            cin >> rng;
            cout << "Inroduzca un limite inferior y superior para acotar los numeros generados.\n >>";
            cin >> bot >> top;
            laRistra=genLaRistra(rng,top,bot);
            break;
        default:
            std::cin.clear();
            std::cin.ignore();
            break;
        }

    }while(choose!=5);


    return 0;
}