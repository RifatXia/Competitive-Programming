template <class T, class = void>
struct is_iterable : std::false_type
{
};

#ifdef __cpp_lib_void_t
template <class T>
struct is_iterable<T, std::void_t<decltype(std::begin(std::declval<T>())),
                                  decltype(std::end(std::declval<T>()))>>
    : std::true_type
{
};
#else
template <typename... Ts>
struct make_void
{
    typedef void type;
};
template <typename... Ts>
using void_t = typename make_void<Ts...>::type;

template <class T>
struct is_iterable<T, void_t<decltype(std::begin(std::declval<T>())),
                             decltype(std::end(std::declval<T>()))>>
    : std::true_type
{
};
#endif

#define PAIR_SEP ","
template <class T1, class T2>
constexpr std::ostream &operator<<(std::ostream &out, const std::pair<T1, T2> &p)
{
    out << p.first << PAIR_SEP << p.second;
    return out;
}

#define ITER_SEP " "
template <class Iterable,
          class = typename std::enable_if<is_iterable<Iterable>::value &&
                                          !std::is_convertible<Iterable,
                                                               std::string>::value>::type>
constexpr std::ostream &operator<<(std::ostream &out, const Iterable &v)
{
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        if (it != v.begin())
            out << ITER_SEP;
        out << *it;
    }
    return out;
}

template <class Iterable,
          class = typename std::enable_if<is_iterable<Iterable>::value &&
                                          !std::is_convertible<Iterable,
                                                               std::string>::value>::type>
constexpr std::istream &operator>>(std::istream &in, Iterable &v)
{
    for (auto &x : v)
    {
        in >> x;
    }
    return in;
}

template <class T1, class T2>
constexpr std::istream &operator>>(std::istream &in, std::pair<T1, T2> &p)
{
    in >> p.first >> p.second;
    return in;
}
