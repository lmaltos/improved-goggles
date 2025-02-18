#ifndef CLASET_H
#define CLASET_H

template <class D>
class ClaseT {
  private:
    D data;
  public:
    ClaseT(D);
    void setData(D);
    D getData();
};

template <class D>
ClaseT<D>::ClaseT(D d) {
    data = d;
}

template <class D>
void ClaseT<D>::setData(D x) {
    data = x;
}

template <class T>
T ClaseT<T>::getData() {
    return data;
}


#endif