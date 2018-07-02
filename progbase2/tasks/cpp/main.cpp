
#include <iostream>
#include <string>
#include <point2d.h>
#include <vector>
#include <list>




int main(void){

    vector<Point*> array;

     array.insert(array.end(), new Point(16,18,"dot1"));
     array.insert(array.end(), new Point(98,5,"dot2"));
    
    //array.insert(array.end(), new Point(4, 14, "esffe"));
    
    
    string option;
    string print = "print";
    string newel = "add";
    string find = "find";
    string exit = "exit";
    while(1){
        int size = array.size();
        system("clear");
        cout << "\nВиберіть дію" << "\n print - надрукувати структури" << "\n add - додати новий елемент"
         << "\n find - найти точки в яких довжина менша введеної" << "\n exit - вихід\n";     
        getline(cin, option);
       
           
        if(option == "print"){
            for(int i = 0; i < size; i++) {
                array[i]->Print();
            }
            cout << "Якщо бажаєте продовжити нажміть на 1";
            int op;
            cin >> op;
            if(op == 1){
                continue;
            } 
        }
       if(option == newel){
          // system("clear");
           int x;
           int y;
           string name;
           cout << "Puts x" << endl;
           cin >> x;
           cout << "Puts y" << endl;
           cin >> y;
           cout << "Puts name" << endl;
           cin >> name;
           array.insert(array.end(), new Point(x, y, name));
       }
       if(option == find){
            //system("clear");
            int length;
            cout << "Введіть довжину відносно якої вивести точки";
            cin >> length;
            for(int i = 0; i < size; i++){
                if(array[i]->vectorlength() < length){
                    array[i]->Print();
                }
            }
            cout << "Якщо бажаєте продовжити нажміть на 1";
            int op;
            cin >> op;
            if(op == 1){
                continue;
            } 
       }
       if(option == exit){
           break;
       }


   }
   int size = array.size();
   //array.clear();

   for(int i = 0; i < size; i++){
        delete array[i];
   }

//    float length = New.vectorlength();
//    cout << length;

    return 0;
}

