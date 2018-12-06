template <class T>
const T& max (const T& a) {
  if(a < 0)
    return -a;
  else
    return a;
}
