#include <Python.h>

// ============================= C code =============================

long long int c_fib_iter(int num) {
    /* Returns the nth Fibonacci number (using iteration)*/

    long long int a = 0, b = 1, c, i; 
    if( num == 0)
    	return a;
    
    for (i = 2; i <= num; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

long long int c_fib_rec(int num) {
    /* Returns the nth Fibonacci number (using recursion)*/
    if (num == 1 || num == 2)
        return 1;
    else
        return c_fib_rec(num - 1) + c_fib_rec(num - 2);
}

int c_isprime(int num){
    /* Check if a number is prime */

    int i, flag = 0;

    if (num == 0 || num == 1)
        flag = 1;

    for (i = 2; i <= num / 2; ++i) {
        if (num % i == 0) {
            flag = 1;
            break;
        }
    }

    if (flag == 0)
        return 1;
    else
        return 0;
}


// ============================= Boilerplate code to compile C code into python =============================

// ---------- C function ----------
static PyObject* fib_iter(PyObject* self, PyObject* args){
    long long int num, n;

    if (!PyArg_ParseTuple(args, "i", &num))
        return NULL;
    
    n = c_fib_iter(num);

    return PyLong_FromLongLong(n);
}

static PyObject* fib_rec(PyObject* self, PyObject* args){
    long long int num, n;

    if (!PyArg_ParseTuple(args, "i", &num))
        return NULL;
    
    n = c_fib_rec(num);

    return PyLong_FromLongLong(n);
}

static PyObject* isprime(PyObject* self, PyObject* args){
    long long int num;
    int n;

    if (!PyArg_ParseTuple(args, "i", &num))
        return NULL;
    
    n = c_isprime(num);

    return PyBool_FromLong(n);
}

// ---------- Version ----------
static PyObject* version(PyObject* self){
    return Py_BuildValue("s", "Version 0.0.1");
}

// ---------- defination ----------
static PyMethodDef _cmath_func[] = {
    {"fib_iter", fib_iter, METH_VARARGS, "Function to get the nth Fibonacci number using iteration"},
    {"fib_rec", fib_rec, METH_VARARGS, "Function to get the nth Fibonacci number using recursion"},
    {"isprime", isprime, METH_VARARGS, "Function to check if a number is prime or not"},
    {"version", (PyCFunction)version, METH_NOARGS, "returns the version of the module"},
    {NULL, NULL, 0, NULL}
};

// ---------- implementation ----------
static struct PyModuleDef cmath_func = {
    PyModuleDef_HEAD_INIT,
    "cmath_func",
    "fib_iter, fib_rec, isprime Module",
    -1,  // global state
    _cmath_func
};

// ---------- initializer ----------
PyMODINIT_FUNC PyInit_cmath_func(void){
    return PyModule_Create(&cmath_func);
}