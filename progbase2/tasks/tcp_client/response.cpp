#include "response.h"

Response::Response(QString jsonString)
{
    QJsonDocument jdoc = QJsonDocument::fromJson(jsonString.toUtf8());
    QJsonValue value = jdoc.object().value("status");
    //int status = value.toBool();
    this->status = value.toBool();
    vector<int> final;

    if (jdoc.isObject() && this->status == true ) {
        QJsonValue value = jdoc.object().value("data");
        QJsonArray array = value.toArray();
        foreach (const QJsonValue & v, array){
            this->numbers.push_back(v.toInt());
        }
    }
    this->error = "";
    if(this->status == false){
        QJsonValue value = jdoc.object().value("error");
        this->error =  value.toString();
    }
}

void Response:: print(){
    if (this->status == true ) {
        vector<int> final;
        cout <<"Сформувати новий вектор чисел за правилом: якщо елемент вхідного масиву додатній -"
               " він перетворюється на 1, у іншому випадку - на 0. Розбити цей вектор на послідовності "
               "по 8 чисел та відкинути неповну послідовність (де кількість чисел <8)."
               " Перетворити кожну 8-мку чисел (0 та 1) на число у десятковій системі числення і"
               " записати у новий вектор." << endl;
        cout << endl;
        cout << "Aray of numbers" << endl;

        for(int i = 0; i < this->numbers.size(); i++){
            cout << this->numbers[i] << " ";
        }
        cout << endl;
        vector<int> bin;
        for(int i = 0; i < this->numbers.size();i++){
            if(this->numbers[i] >= 0){
                bin.push_back(1);
            }
            else{
                bin.push_back(0);
            }
        }
        cout << "\nNew array of numbers 1 - if number is positive and 0 - if nubber is nagative" << endl;
        for(int i = 0; i < bin.size(); i++){
            cout << bin[i] << " ";
        }
        vector<int> number;
        for(int i = 0; i < bin.size();i++){
            number.push_back(bin[i]);
            if(number.size() == 8){
                int k = 0;
                int num = 0;
                for(int j = number.size() - 1; j >0 ;j--, k++){
                    if(number[j] == 1){
                        num += pow(2,k);
                    }
                }
                final.push_back(num);
                number.clear();
            }
        }
        cout << "\nFinal array" <<endl;
        for(int i = 0; i < final.size(); i++){
            cout << final[i] << " ";
        }
    }
    else{
        qDebug() << this->error << endl;
    }
}
