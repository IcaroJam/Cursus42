template<typename T> Array<T>::Array() {
	_len = 0;
	_arr = new T[0];
}

template<typename T> Array<T>::Array(unsigned int n) {
	_len = n;
	_arr = new T[n];
	/*for (unsigned int i = 0; i < n; i++)
		_arr[i] = 0;*/
}

template<typename T> Array<T>::Array(const Array &cpyFrom) {
	*this = cpyFrom;
}

template<typename T> Array<T> &Array<T>::operator=(const Array &cpyFrom) {
	_len = cpyFrom._len;
	for (unsigned int i = 0; i < _len; i++)
		_arr[i] = cpyFrom._arr[i];
}

template<typename T> Array<T>::~Array() {
	delete[] _arr;
}

template<typename T> T	&Array<T>::operator[](unsigned int i) const {
	if (i >= _len)
		throw std::out_of_range("out_of_range exception: index out of array bounds.");
	return (_arr[i]);
}

template<typename T> unsigned int	Array<T>::size(void) const {return (_len);}
