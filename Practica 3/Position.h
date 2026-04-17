#ifndef POSITION_H
#define POSITION_H

template <class Key, class Value>
class Position {
public:
    Position(const Key key);
    Position(const Position<Key, Value>& orig);
    virtual ~Position();
    /* Modificadors */
    // Declareu-hi aquí els modificadors (setters) dels atributs que manquen
    
    /* Consultors */
    const Key& getKey() const;
    const vector<Value>& getValues() const;
    // Declareu-hi aquí els consultors (getters) dels atributs que manquen

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
    // Afegiu-hi aquí els atributs que manquen    
};
#endif //POSITION_H