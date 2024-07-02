# cpp_task4


## תיאור הפרויקט
פרויקט זה מכיל מגוון מחלקות ופונקציות המשמשות ליישום אלגוריתמים ואיטרטורים שונים. הפרויקט נכתב בשפת C++ ומשתמש במספר קבצי כותרות (headers) וקבצים מקוריים (source).

## מבנה הפרויקט
הפרויקט כולל את הקבצים הבאים:
- bfs_iterator.hpp
- dfsiterator.hpp
- heap_iterator.hpp
- in_order_iterator.hpp
- node.hpp
- PostOrderIterator.hpp
- PreOrderiterator.hpp
- demo.cpp
- doctest.h

### bfs_iterator.hpp
קובץ זה מכיל מימוש של איטרטור BFS (Breadth-First Search) עבור עצים או גרפים. 

### dfsiterator.hpp
קובץ זה מכיל מימוש של איטרטור DFS (Depth-First Search) עבור עצים או גרפים.

### heap_iterator.hpp
קובץ זה מכיל מימוש של איטרטור עבור מבנה נתונים מסוג Heap (ערימה).

### in_order_iterator.hpp
קובץ זה מכיל מימוש של איטרטור In-Order עבור עצים בינאריים.

### node.hpp
קובץ זה מכיל את מימוש מחלקת Node, המשמשת לייצוג צומת בעץ או גרף. 

### PostOrderIterator.hpp
קובץ זה מכיל מימוש של איטרטור Post-Order עבור עצים בינאריים.

### PreOrderiterator.hpp
קובץ זה מכיל מימוש של איטרטור Pre-Order עבור עצים בינאריים.

### demo.cpp
קובץ זה מכיל דוגמת שימוש במחלקות ובאיטרטורים שהוגדרו בקבצים האחרים.

### doctest.h
קובץ זה מכיל את הספרייה doctest לבדיקות יחידה.

## פונקציות עיקריות

### מחלקת BFSIterator
- `BFSIterator(Node* root)`: קונסטרוקטור שמקבל מצביע לשורש העץ.
- `bool hasNext()`: בודק אם יש עוד צומת לבקר.
- `Node* next()`: מחזיר את הצומת הבא.

### מחלקת DFSIterator
- `DFSIterator(Node* root)`: קונסטרוקטור שמקבל מצביע לשורש העץ.
- `bool hasNext()`: בודק אם יש עוד צומת לבקר.
- `Node* next()`: מחזיר את הצומת הבא.

### מחלקת HeapIterator
- `HeapIterator(Node* root)`: קונסטרוקטור שמקבל מצביע לשורש הערימה.
- `bool hasNext()`: בודק אם יש עוד צומת לבקר.
- `Node* next()`: מחזיר את הצומת הבא.

### מחלקת InOrderIterator
- `InOrderIterator(Node* root)`: קונסטרוקטור שמקבל מצביע לשורש העץ.
- `bool hasNext()`: בודק אם יש עוד צומת לבקר.
- `Node* next()`: מחזיר את הצומת הבא.

### מחלקת PostOrderIterator
- `PostOrderIterator(Node* root)`: קונסטרוקטור שמקבל מצביע לשורש העץ.
- `bool hasNext()`: בודק אם יש עוד צומת לבקר.
- `Node* next()`: מחזיר את הצומת הבא.

### מחלקת PreOrderIterator
- `PreOrderIterator(Node* root)`: קונסטרוקטור שמקבל מצביע לשורש העץ.
- `bool hasNext()`: בודק אם יש עוד צומת לבקר.
- `Node* next()`: מחזיר את הצומת הבא.

### מחלקת Node
- `Node(int value)`: קונסטרוקטור שמקבל ערך.
- `int getValue()`: מחזיר את הערך של הצומת.
- `Node* getLeft()`: מחזיר מצביע לצומת השמאלי.
- `Node* getRight()`: מחזיר מצביע לצומת הימני.
