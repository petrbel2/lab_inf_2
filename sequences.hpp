#ifndef SEQUENCES_H 
#define SEQUENCES_H

template <typename data_type>
class Sequence
{
public:
    virtual data_type Get(int index) = 0;

    virtual int GetLength() = 0;

    virtual void Append(data_type new_elem) = 0;

    virtual void Prepend(data_type new_elem) = 0;

    virtual void InsertAt(data_type new_elem, int postion) = 0;
};

#endif