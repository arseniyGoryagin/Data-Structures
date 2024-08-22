


template<typename T>

class StackArray{



    int top = -1;

    T * array = nullptr;
    const int size = 0;



    public:


    StackArray(int size){
        array = new T[size];
    }


    void push(T value){
        top = top +1;
        array[top] = value;
    }


    T pop(){
        top = top -1;
        return array[top+1];
    }




};