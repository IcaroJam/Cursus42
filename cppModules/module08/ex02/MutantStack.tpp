template <typename T> MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T> MutantStack<T>::MutantStack(const MutantStack &cpyFrom) {
	*this = cpyFrom;
}

template <typename T> MutantStack<T> &MutantStack<T>::operator=(const MutantStack &cpyFrom) {
	*this = cpyFrom;
	return (*this);
}

template <typename T> MutantStack<T>::~MutantStack() {}

template <typename T> typename std::stack<T>::container_type::iterator	MutantStack<T>::begin(void) {
	return (this->c.begin());
}

template <typename T> typename std::stack<T>::container_type::iterator	MutantStack<T>::end(void) {
	return (this->c.end());
}
