/*
 * Created on January 8, 2012, 10:05 PM
 * By Laurent Victorino < laurent.victorino@gmail.com >
 */

#ifndef SINGLETON_H
#define	SINGLETON_H

#include <stdlib.h>

template <class T>
class	cSingleton
{

protected:
    cSingleton() {};
    ~cSingleton() {};

private:
    static T	*_instance;

public:
    static T	*getInstance();
    static void	killInstance();
};

template <typename T>
T *cSingleton<T>::_instance = NULL;

template <typename T>
T *cSingleton<T>::getInstance()
{
    if (_instance == NULL)
    {
        _instance = new T;
    }
    return _instance;
}

template <typename T>
void cSingleton<T>::killInstance()
{
	if (_instance != NULL)
	{
	    delete _instance;
		_instance = NULL;
	}
}

#endif	/* SINGLETON_H */

