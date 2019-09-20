class ComplexNumber {
    int Re;
    int Im;
public:
    explicit constexpr ComplexNumber(int x = 0, int y = 0) :Re(x), Im(y) { }
    constexpr void SetRe(int x)
    {
        Re = x;
    }
    constexpr void SetIm(int x)
    {
        Im = x;
    }
    constexpr int GetRe() const
    {
        return Re;
    }
    constexpr int GetIm() const
    {
        return Im;
    }
    constexpr bool operator==(const ComplexNumber &obj) const {
        return Re == obj.Re && Im == obj.Im;
    }
};

constexpr ComplexNumber Conjugate(const ComplexNumber &x) {
    ComplexNumber res;
    res.SetRe(x.GetRe());
    res.SetIm(-x.GetIm());
    return res;
}

int main() {
    constexpr ComplexNumber a(1, 2);
    constexpr ComplexNumber b(1, -2);
    constexpr auto c = Conjugate(a);
    static_assert(b == c, "failed");
}