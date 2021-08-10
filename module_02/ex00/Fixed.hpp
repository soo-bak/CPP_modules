class Fixed {
  public:
    Fixed(void);
    Fixed(const Fixed& fixed);
    ~Fixed(void);

    int getRawBits(void) const;
    void setRawBits(int const raw);
    Fixed& operator = (const Fixed& source);

  private:
    int fixedPointValue;
    static const int fractionalBitsNumber;
};
