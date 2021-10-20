#include "Container.h"

Container::Container(int size): size_(size), len_(0) {
    storage_ = new RoadTransport*[size];
}

Container::~Container() {
    for (int i = 0; i < len_; ++i) {
        delete storage_[i];
    }
    delete []storage_;
}

void Container::read(std::ifstream& in) {
    while (!in.eof()) {
        // Проверка на случай ввода более 10000 данных из файла.
        if (len_ == size_) {
            std::cout << size_ << " objects were inputted.\n"
                      << "Container is full. Next objects will be ignored.\n";
            return;
        }
        storage_[len_] = RoadTransport::staticRead(in);
        ++len_;
    }
}

void Container::generate(int size, bool realistic_random) {
    while (len_ < size) {
        storage_[len_] = RoadTransport::staticGenerate(realistic_random);
        ++len_;
    }
}

void Container::print(std::ofstream& out) {
    out << "Total objects in container: " << len_ << "\n";
    printHeader(out);
    for (int i = 0; i < len_; ++i) {
        storage_[i]->print(out);
    }
}

// Вспомогательный метод. Его применение предполагает, что ему дается мин-куча, где только корень нарушает структуру.
// Метод за O(log2(кол-во элементов в дереве)) последовательными свопами перемещает корень в нужное место в мин-куче.
void heapify(RoadTransport **data, double *keys, const int &len, int root) {
    int smallest = root;
    int l = root * 2 + 1;
    int r = root * 2 + 2;

    if (l < len && keys[l] < keys[smallest]) {
        smallest = l;
    }
    if (r < len && keys[r] < keys[smallest]) {
        smallest = r;
    }

    if (root != smallest) {
        std::swap(keys[root], keys[smallest]);
        std::swap(data[root], data[smallest]);
        heapify(data, keys, len, smallest);
    }
}

void Container::heapSort() {
    double keys[len_];
    for (int i = 0; i < len_; ++i) {
        keys[i] = storage_[i]->maxDistance();
    }

    // В начале нужно создать из неструктурированного массива мин-кучу.
    // Эта операция похожа на индукцию.
    // Начинаю запускать с нижних поддеревьев из трех элементов (база).
    // На всех следующих элементах оказывается, что два поддерева у корня являются мин-кучами (шаг индукции)
    // И только корень поддерева нарушает структуру, поэтому применяется heapify.
    for (int i = len_ / 2 - 1; i >= 0; --i) {
        heapify(storage_, keys, len_, i);
    }

    // Для создания отсортированного массива
    // Каждый раз убираем корень дерева и ставим на его место последний элемент мин-кучи.
    // После чего применяем heapify, чтобы опять наверху оказался минимальный элемент.
    for (int i = len_ - 1; i >= 0; --i) {
        std::swap(storage_[0], storage_[i]);
        std::swap(keys[0], keys[i]);
        // Применение heapify опускает корневой элемент ниже по дереву до подходящего места.
        heapify(storage_, keys, i, 0);
    }
}

bool Container::isSortedByDescendingOrder() {
    for (int i = 0; i < len_ - 1; ++i) {
        if (storage_[i]->maxDistance() < storage_[i + 1]->maxDistance()) {
            return false;
        }
    }
    return true;
}
