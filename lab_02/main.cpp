#include <iostream>

#include <vector.hpp>

using namespace std;

int main()
{
    Vector<double> initializing = {5, 2, 15};
    const Vector<int> constVect = {0, 1, 2, 3, 4};
    Vector<float> lenExample(3);
    Vector<double> lenFillExample(3, 6.66, 7.5, 8.6);
    Vector<long double> emptyVector(0);

    cout<< "Vector with initialization: "<< initializing<< endl;
    cout<< "Vector with a given length "<< lenExample<< endl;
    cout<< "Vector of a given length with initialization: "<< lenFillExample<< std::endl;
    cout<< "Empty vector: "<< emptyVector<< endl;

    Vector<int> operVecF = {4, 2, 4};
    Vector<int> operVecS = {3, 1, 5};
    Vector<double> oper = {1.0, 2.0, 1.0};
    //cout<< (oper / 10.0) << endl;
    cout<< "Normalization of the vector: "<< operVecS << "=>" << operVecS.getSingle() << endl;
    cout<< "Size vector: " << initializing.getSize()<< endl;
    cout<< "Vector length: "<<initializing.getLength()<< endl;
    cout<< "Is the vector zero: "<<initializing.isZero()<< endl;
    cout<< "Is a single vector: "<<initializing.isSingle()<< endl;
    cout<< "Angle between vectors: "<< lenFillExample.angleBetweenVectors(initializing)<< endl;


    cout<< "Setting the second element to 10: "<<initializing.setItem(1, 10)<< endl;
    cout<< "The second element of the vector: "<<initializing.getItem(1)<< endl;
    cout<< "The second element of the constant vector: "<<constVect.getItem(1)<< endl;

    cout<< "Vectors *: "<< operVecF << " * " <<  operVecS << " = " << operVecF * operVecS<< endl;
    cout<< "Vectors +: "<< operVecF << " + " <<  operVecS << " = " << operVecF + operVecS<< endl;
    cout<< "Vectors -: "<< operVecF << " - " <<  operVecS << " = " << operVecF - operVecS<< endl;
    cout<< "Vectors &(vector Multy): "<< operVecF << " & " <<  operVecS << " = " << (operVecF & operVecS) << endl;

    cout<< operVecF << " * 10" << " = " <<  operVecF * 10 << endl;
    cout<< operVecF << " / 2" << " = " <<  operVecF / 2 << endl;

    Vector<float> orthVecF = {1, 0, 0};
    Vector<float> orthVecS = {0, 1, 0};
    Vector<float> nonOrthVec = {1, 2, 3};

    cout<< "Orthogonality: "<< orthVecF.isOrthgonal(orthVecS)<< endl;
    cout<< "Not orthogonality: "<<orthVecF.isOrthgonal(nonOrthVec)<< endl;

    Vector<int> colVecF = {1, 1, 0};
    Vector<int> colVecS = {1, 1, 0};

    cout<< "Collinearity: "<< colVecF.isCollinear(colVecS)<< endl;
    cout<< "Not collinearity: "<< colVecF.isCollinear(operVecF)<< endl;

    try {
        orthVecF.isCollinear(lenExample);
    } catch (ZeroDivError &er) {
            cout<< "\nFind error:"<< er.what()<< endl;
    }

    try {
        Vector<float> vectempty(0, 1, 2 ,3);
        orthVecF.isCollinear(vectempty);
    } catch (EmptyVectorError &er) {
        cout<< "Find error:"<< er.what()<< endl;
    }

    try {
        orthVecF.getItem(-1);
    } catch (IndexVectorError &er) {
        cout<< "Find error:"<< er.what()<< endl;
    }

    return 0;
}
