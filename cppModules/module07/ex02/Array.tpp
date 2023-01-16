template<typename T> Array<T>::Array() {
	len = 0;
	arr = new T[0];
}

template<typename T> Array<T>::Array(unsigned int n) {
	len = n;
	arr = new T[n];
	for (unsigned int i = 0; i < n; i++)
		arr[i] = 0;
}

template<typename T> Array<T>::Array(const Array &cpyFrom) {
	*this = cpyFrom;
}

template<typename T> Array<T> &Array<T>::operator=(const Array &cpyFrom) {
	len = cpyFrom.len;
	for (unsigned int i = 0; i < len; i++)
		arr[i] = cpyFrom.arr[i];
}

template<typename T> Array<T>::~Array() {
	delete[] arr;
}

template<typename T> T	&Array<T>::operator[](unsigned int i) const {
	try {
		if (i >= len)
			throw std::out_of_range("EXCEPTIONTEST");
		return (arr[i]);
	} catch(std::exception &excep) {
		std::cerr << excep.what() << std::endl;
	}
}

template<typename T> unsigned int	Array<T>::size(void) const {return (len);}
