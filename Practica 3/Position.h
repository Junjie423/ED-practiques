#ifndef POSITION_H
#define POSITION_H

template <class Key, class Value>
class Position {
public:
    Position(const Key key);
    Position(const Position<Key, Value>& orig);
    virtual ~Position();
    
    /* Modificadors */
    void setParent(Position<Key, Value>* pos);
    void setLeft(Position<Key, Value>* pos);
    void setRight(Position<Key, Value>* pos);
    
    /* Consultors */
    const Key& getKey() const;
    const vector<Value>& getValues() const;
    Position<Key, Value> parent() const;
    Position<Key, Value> left() const;
    Position<Key, Value> right() const;

    /* Operacions */
    bool isRoot() const;
    bool isLeaf() const;
    int depth() const;
    int height() const;
    void addValue(const Value& value);
    bool operator==(const Position<Key, Value>& other) const;
    
private:
    Key key;
    vector<Value> values;
    Position<Key, Value> pare;
    Position<Key, Value> esq;
    Position<Key, Value> dret;
};
#endif //POSITION_H