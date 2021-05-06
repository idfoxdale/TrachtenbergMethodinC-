class Trachtenberg
{
public:
  void multiply(const char* a, const char* b)
  {
    size_t large = strlen(a);
    size_t small = strlen(b);
    if (large == 0 || small == 0) {
      answer = solution = new char[2]{ '0', '\0' };
      return;
    }
    if (large < small) {
      std::swap(a, b);
      std::swap(large, small);
    }
    solution = new char[large + small];
    answer = solution + large + small - 1;
    *answer = '\0'; // zero terminate
    size_t digits = 0;
    const char* starta = a + large;
    const char* startb = b + small;
    intermediate = 0;
    while (digits != small) {
      multiplystep(++digits, --starta, startb);
    }
    for (size_t d = digits; d != large; ++d) {
      multiplystep(digits, --starta, startb);
    }
    while (digits != 1) {
      multiplystep(--digits, starta, --startb);
    }
    while (intermediate) {
      *--answer = '0' + intermediate % 10;
      intermediate /= 10;
    }
  }
  const char* result() const { return answer;  }

private:
  size_t intermediate;
  char* solution = nullptr;
  char* answer = nullptr;

  void multiplystep(size_t digits, const char* starta, const char* startb)
  {
    const char* digita = starta;
    const char* digitb = startb;
    for (size_t n = 0; n != digits; ++n) {
      --digitb;
      intermediate += (*digita - '0') * (*digitb - '0'); // convert from ASCII string
      ++digita;
    }
    *--answer = '0' + intermediate % 10; // convert back to string
    intermediate /= 10;
  }
};
