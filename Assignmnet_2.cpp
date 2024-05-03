#include <iostream>
#include <string>

class Vemaybay {
private:
    std::string tenchuyen;
    std::string ngaybay;
    int giave;

public:
    Vemaybay(std::string tenchuyen = "", std::string ngaybay = "", int giave = 0) {
        this->tenchuyen = tenchuyen;
        this->ngaybay = ngaybay;
        this->giave = giave;
    }

    ~Vemaybay() {
        this->tenchuyen= "";
        this->ngaybay = "";
        this->giave = 0;
    }

    void Nhap() {
        std::cout << "Nhap ten chuyen: ";
        std::getline(std::cin, this->tenchuyen);
        std::cout << "Nhap ngay bay: ";
        std::getline(std::cin, this->ngaybay);
        std::cout << "Nhap gia ve: ";
        std::cin >> this->giave;
        std::cin.ignore();
    }

    int getGiave() const {
        return this->giave;
    }

    void Xuat() const {
        std::cout << "Chuyen bay: " << this->tenchuyen  << "\n"
        << "Ngay bay: " << this->ngaybay << "\n"
        << "Gia ve: " << this->giave << "\n";
    }
};

class Nguoi {
private:
    std::string ten;
    std::string gioitinh;
    int tuoi;
public:
    Nguoi(std::string ten = "", std::string gioitinh = "", int tuoi = 0) {
        this->ten = ten;
        this->gioitinh = gioitinh;
        this->tuoi = tuoi;
    }

    ~Nguoi() {
        this->ten = "";
        this->gioitinh = "";
        this->tuoi = 0;
    }

    void Nhap() {
        std::cout << "Nhap ten: ";
        std::getline(std::cin, this->ten);
        std::cout << "Nhap gioi tinh: ";
        std::getline(std::cin, this->gioitinh);
        std::cout << "Nhap tuoi: ";
        std::cin >> this->tuoi;
        std::cin.ignore();
    }

    void Xuat() const {
        std::cout << "Ten: " << this->ten << "\n"
                << "Gioi tinh: " << this->gioitinh  << "\n"
                << "Tuoi: " << this->tuoi << "\n";
    }
};

class hanhkhach : public Nguoi {
private:
    Vemaybay* ve;
    int soluong;
public:
    hanhkhach(std::string ten, std::string gioitinh, int tuoi, Vemaybay* ve, int soluong) : Nguoi(ten, gioitinh, tuoi) {
        this->ve = ve;
        this->soluong = soluong;
    }

    ~hanhkhach() {
        delete ve;
        this->soluong = 0;
    }

    void Nhap() {
        Nguoi::Nhap();
        ve = new Vemaybay();
        ve->Nhap();
        std::cout << "Nhap so luong: ";
        std::cin >> this->soluong;
        std::cin.ignore();
    }

    void Xuat() const {
        Nguoi::Xuat();
        ve->Xuat();
        std::cout << "So luong: " << this->soluong << "\n";
    }

    int getTongtien() const {
        return this->soluong * ve->getGiave();
    }
};

int main() {
    int n;
    std::cout << "Nhap so hanh khach: ";
    std::cin >> n;
    std::cin.ignore();

    hanhkhach** arr = new hanhkhach*[n];
    for (int i = 0; i < n; i++) {
        std::string ten, gioitinh;
        int tuoi;
        Vemaybay* ve = nullptr;
        int soluong;
        arr[i] = new hanhkhach(ten, gioitinh, tuoi, ve, soluong);
        std::cout << "Nhap thong tin hanh khach thu " << i + 1 << ":\n";
        arr[i]->Nhap();
    }

    for (int i = 0; i < n; i++) {
        std::cout << "Thong tin hanh khach thu " << i + 1 << ":\n";
        arr[i]->Xuat();
    }

    return 0;
}
