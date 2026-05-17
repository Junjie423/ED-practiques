#ifndef TUPLE_H
#define TUPLE_H
using namespace std;

template<class Element> 
class Tuple {
public:
    Tuple(); // O(1)
    
    // consultors
    const Element& getFila() const; // O(1)
    const Element& getColumna() const; // O(1)

    // Modificadors
    void setFila(const Element& fila); // O(1)
    void setColumna(const Element& col); // O(1)

    // Operacions
    bool operator==(const Tuple<Element>& other) const; // O(1)
    bool operator<(const Tuple<Element>& other) const; // O(1)


private:
    Element _fila;
    Element _col;
};

// Constructor
template<class Element> Tuple<Element>::Tuple(){
    this->_fila = 0;
    this->_col = 0;
}

// Consultors
template<class Element> const Element& Tuple<Element>::getFila() const{
    return this->_fila;
}

template<class Element> const Element& Tuple<Element>::getColumna() const{
    return this->_col;
}

// Modificadors
template<class Element> void Tuple<Element>::setFila(const Element& fila){
    this->_fila = fila;
}

template<class Element> void Tuple<Element>::setColumna(const Element& col){
    this->_col = col;
}

// Operacions
template<class Element> bool Tuple<Element>::operator==(const Tuple<Element>& other) const{
    return ((this->_fila == other._fila) && (this->_col == other._col));
}

template<class Element> bool Tuple<Element>::operator<(const Tuple<Element>& other) const{
    if (this->_fila != other._fila) {
        return this->_fila < other._fila;
    } else{
        return this->_col < other._col;
    }
}

#endif // TUPLE_H