#include "Test.h"

void Test::test1()
{
    cout << "Check class methods\n";

    int array[15] = { 1, 250, 120, 44, 20, 2, 18, 5, 2, 312, 50 };
    int* ptrArray = array;
    Array myArr(15, 11, ptrArray);

    cout << "Original Array: " << myArr.toString() << "\n\n";

    cout << "Adding 45, 30 at the starting of the array\n";
    try {
        myArr.add(45, 0);
        myArr.add(30, 0);
    }
    catch (ArrayException& e) {
        cout << "==================================\n" << e.what() << "\n==================================\n";
    }

    cout << "At the end of the Array add 19\n";
    myArr.add(19);
    cout << "At the end of the Array add 33\n";
    myArr.add(33);
    cout << "At the end of the Array add 7\n";
    myArr.add(7);
    cout << "At the end of the Array add 100\n";
    myArr.add(100);
    cout << std::endl << myArr.toString() << std::endl;

    int* expectedArray = new int[myArr.getArraySize()]{ 45, 30, 1, 250, 120, 44, 20, 2, 18, 5, 2, 312, 50, 19, 33, 7, 100 };

    int* ptrExpectedArray = expectedArray;
    cout << "Expected is equal: " << equal(myArr, ptrExpectedArray) << "\n";
    delete[] expectedArray;

    cout << "delete the first element twice\n";
    try {
        myArr.deleteElement(0);
        myArr.deleteElement(0);
    }
    catch (ArrayException& e) {
        cout << "==================================\n" << e.what() << "\n==================================\n";
    }

    cout << "Collaps array to the last element not null\n";
    myArr.collapse();
    cout << "---------------------------------\n";
    cout << myArr.toString() << std::endl;
    expectedArray = new int[myArr.getArraySize()]{ 1, 250, 120, 44, 20, 2, 18, 5, 2, 312, 50 };
    ptrExpectedArray = expectedArray;
    cout << "Expected Real array is equal: " << equal(myArr, ptrExpectedArray) << "\n";
    delete[] expectedArray;

    cout << "Sort array\n";
    myArr.sort();
    cout << "---------------------------------\n";
    cout << myArr.toString() << std::endl;
    cout << "---------------------------------\n";

    try {
        cout << "Index: " << myArr.getIndex() << ", The last element not null: " << myArr.getElement(myArr.getIndex() - 1)
            << ", Max array size: " << myArr.getArraySize();
    }
    catch (ArrayException& e) {
        cout << "==================================\n" << e.what() << "\n==================================\n";

    }

    cout << "\n" << myArr.toString() << std::endl;
    cout << "---------------------------------\n";

    cout << "Number '18' element having index " << myArr.findElement(18) << std::endl;

    try {
        myArr.replace(1111, 0);
    }
    catch (ArrayException& e) {
        cout << "==================================\n" << e.what() << "\n==================================\n";
    }
    cout << "\nReplace the first item of index 0\n" << myArr.toString() << std::endl;

    expectedArray = new int[myArr.getArraySize()]{ 1111, 12, 22, 33, 10, 19, 7, 14, 5, 6, 11, 33, 35, 99, 44 };
    ptrExpectedArray = expectedArray;
    cout << "Expected array is equal to: " << equal(myArr, ptrExpectedArray) << "\n";
    delete[] expectedArray;

}

void Test::test2()
{
    cout << "\n==============================================\n\n";
    cout << "Test 2: Check classes methods and exceptions \n\n\n";

    Array myArr;

    cout << "Index: " << myArr.getIndex() << ", The last element not null: " << myArr.getElement(myArr.getIndex())
        << ", Maximum array size: " << myArr.getArraySize();

    cout << "\nAdd 66 to the end of the\n";
    myArr.add(66);
    cout << "Add 55 to the end of the\n";
    myArr.add(55);
    cout << "Add 99 to the end of the\n";
    myArr.add(99);
    cout << "Add 11 to the end of the\n";

    try {
        myArr.add(11, 0);
    }
    catch (ArrayException& e) {
        cout << "==================================\n" << e.what() << "\n==================================\n";

    }

    cout << "Add 67 to the end of the\n";
    myArr.add(67);

    cout << "\n" << myArr.toString() << std::endl;

    int* expectedArray = new int[myArr.getArraySize()]{ 11, 66, 55, 99, 67 };
    int* ptrExpectedArray = expectedArray;
    cout << "Expected array is equal: " << equal(myArr, ptrExpectedArray) << "\n";
    delete[] expectedArray;

    cout << "---------------------------------\n";

    cout << "flip array size to 10, then back to -1\n";
    try {
        myArr.setArraySize(10);
        myArr.setArraySize(-1);
    }
    catch (ArrayException& e) {
        cout << "==================================\n" << e.what() << "\n==================================\n";
    }

    cout << "Change Index to 0, than to number bigger Max array size\n";
    try {
        myArr.setIndex(0);
        myArr.setIndex(myArr.getArraySize() + 20);
    }
    catch (ArrayException& e) {
        cout << "==================================\n" << e.what() << "\n==================================\n";
    }

    cout << "Current Max array size: " << myArr.getArraySize() << std::endl;
    cout << "Current Index: " << myArr.getIndex() << std::endl;

    cout << "Change array pointer\n";
    int* arr = new int[myArr.getArraySize()];
    myArr.setPtrArray(arr);

    cout << "Fill new array\n\n";
    myArr.add(30);
    myArr.add(15);
    myArr.add(21);
    myArr.add(40);
    myArr.add(11);
    myArr.add(17);
    myArr.add(155);

    try {
        cout << "Index: " << myArr.getIndex() << ", The last no null: " << myArr.getElement(myArr.getIndex() - 1)
            << ", Max array siz: " << myArr.getArraySize();
    }
    catch (ArrayException& e) {
        cout << "==================================\n" << e.what() << "\n==================================\n";
    }

    expectedArray = new int[myArr.getArraySize()]{ 30, 15, 21, 40, 11, 17, 155 };
    ptrExpectedArray = expectedArray;
    cout << "\nExpected and real array is equal: " << equal(myArr, ptrExpectedArray) << "\n";
    delete[] expectedArray;

    cout << "\n" << myArr.toString() << std::endl;
    cout << "---------------------------------\n";
}

void Test::test3()
{
    cout << "\n==============================================\n\n";
    cout << "Test number 3: Checking exception works\n\n\n";

    Array myArr;

    try {
        cout << "Index: " << myArr.getIndex() << ", The last element not null: " << myArr.getElement(myArr.getIndex())
            << ", Max array size: " << myArr.getArraySize();
    }
    catch (ArrayException& e) {
        cout << "==================================\n" << e.what() << "\n==================================\n";
    }

    cout << "\nAdd number 19 at the array end\n";
    myArr.add(19);
    cout << "Add number 1 at the array end\n";
    myArr.add(1);
    cout << "Add number 5 at the array end\n";
    myArr.add(5);
    cout << "Add number 34 at the array start\n";

    try {
        myArr.add(34, 0);
    }
    catch (ArrayException& e) {
        cout << "==================================\n" << e.what() << "\n==================================\n";
    }

    cout << "Add number 14 at the array end\n";
    myArr.add(14);

    cout << "\n" << myArr.toString() << std::endl;

    int* expectedArray = new int[myArr.getArraySize()]{ 34, 19, 1, 5, 14 };
    int* ptrExpectedArray = expectedArray;
    cout << "Expected array is equal: " << equal(myArr, ptrExpectedArray) << "\n";
    delete[] expectedArray;

    cout << "---------------------------------\n";

    cout << "flip Max array size to 10, then to -1\n";
    try {
        myArr.setArraySize(10);
        myArr.setArraySize(-1);
    }
    catch (ArrayException& e) {
        cout << "==================================\n" << e.what() << "\n==================================\n";
    }
    cout << "Try to change Index to number bigger max array size\n";

    try {
        myArr.setIndex(myArr.getArraySize() + 20);
    }
    catch (ArrayException& e) {
        cout << "==================================\n" << e.what() << "\n==================================\n";
    }

    cout << "Add numbers 69, 96, 23 at the end of the array\n";
    myArr.add(69);
    myArr.add(96);
    myArr.add(23);

    try {
        cout << "Index: " << myArr.getIndex() << ", The last element not null: " << myArr.getElement(myArr.getIndex() - 1)
            << ", Max array size: " << myArr.getArraySize();
    }
    catch (ArrayException& e) {
        cout << "==================================\n" << e.what() << "\n==================================\n";
    }

    expectedArray = new int[myArr.getArraySize()]{ 34, 19, 1, 5, 14, 69, 96, 23 };
    ptrExpectedArray = expectedArray;
    cout << "\nExpected and real array is equal: " << equal(myArr, ptrExpectedArray) << "\n";
    delete[] expectedArray;

    cout << "\n" << myArr.toString() << std::endl;
    cout << "---------------------------------\n";
}

void Test::test4()
{
    cout << "\n==============================================\n\n";
    cout << "Test 4: Check if exception works (stops on exception)\n\n\n";

    Array myArr;

    cout << "Index: " << myArr.getIndex() << ", The last not null element: " << myArr.getElement(myArr.getIndex())
        << ", Max array size: " << myArr.getArraySize();

    cout << "\nAdd 28 to the end of the array\n";
    myArr.add(28);
    cout << "Add 17 to the end of the array\n";
    myArr.add(17);
    cout << "Add 255 to the end of the array\n";
    myArr.add(255);
    cout << "Add 88 at the beginning of the array\n";
    myArr.add(88, 0);

    cout << "Add number 78 at the array end\n";
    myArr.add(78);

    cout << "\n" << myArr.toString() << std::endl;

    int* expectedArray = new int[myArr.getArraySize()]{ 88, 28, 17, 255, 78 };
    int* ptrExpectedArray = expectedArray;
    cout << "Expected Array is equal to: " << equal(myArr, ptrExpectedArray) << "\n";
    delete[] expectedArray;

    cout << "---------------------------------\n";

    cout << "Change Max array size to 10, then to -1\n";
    myArr.setArraySize(10);
    myArr.setArraySize(-1);
    cout << "Try to change Index to number bigger max array size\n";

    myArr.setIndex(myArr.getArraySize() + 20);

    cout << "Add numbers 44, 94, 14 to the end of the array\n";
    myArr.add(44);
    myArr.add(94);
    myArr.add(14);

    cout << "Index: " << myArr.getIndex() << ", The last element not: " << myArr.getElement(myArr.getIndex() - 1)
        << ", Max array size: " << myArr.getArraySize();

    expectedArray = new int[myArr.getArraySize()]{ 88, 28, 17, 255, 78, 44, 94, 14 };
    ptrExpectedArray = expectedArray;
    cout << "\nExpected and real array is equal: " << equal(myArr, ptrExpectedArray) << "\n";
    delete[] expectedArray;

    cout << "\n" << myArr.toString() << std::endl;
    cout << "---------------------------------\n";
}

bool Test::equal(Array& array, int* expectedArray)
{
    int* realArray = array.getPtrArray();
    int i = 0;
    while (*expectedArray > 0 && *realArray > 0 && i < array.getIndex()) {
        if (*expectedArray != *realArray) {
            break;
        }
        else {
            if (*(expectedArray + 1) <= 0 && *(realArray + 1) <= 0) {
                return true;
            }
            if (i >= array.getIndex()) {
                break;
            }
        }
        expectedArray++;
        realArray++;
        i++;
    }

    return false;
}
