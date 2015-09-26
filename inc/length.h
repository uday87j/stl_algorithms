#ifndef LENGTH_H_
#define LENGTH_H_

// rectangle.h

#include <cstdint>
#include <ostream>
#include <sstream>

namespace ns_stl	{

    template<typename T>
    class length_t   {

        public:

        typedef T this_type;

        length_t(const T len = T())
        : m_len(len)    {}

        length_t(const length_t& len)
        : m_len(len.len())  {}

        length_t& operator = (const length_t& len)  {
            m_len   = len.len();
            return *this;
        }

        T len() const   { return m_len; }

        std::string repr() const  {
            std::ostringstream os;
            os << m_len;
            return os.str();
        }

        private:

        T m_len;

    };

    template<typename T>
    std::ostream& operator << (std::ostream& os, const length_t<T>& len)   {
        os << len.repr();
        return os;
    }

    template<typename T>
    bool operator < (const length_t<T>& l1, const length_t<T>& l2)    {
        return l1.len() < l2.len();
    }

    //TODO: Get this compiling
    //// unsigned long long int is the only allowed integral type for "" operator
    //// _m refers to SI unit of length: metre
    //template<typename T>
    ////length_t<T> operator "" _m(std::uint64_t len)  {
    //length_t<T> operator "" _m(unsigned long long int len)  {
    //    T tlen  = static_cast<T>(len);
    //    return length_t<T>(tlen);
    //}

    template<typename T>
    class rectangle_t   {

        public:

        typedef T this_type;

        rectangle_t(const length_t<T>& h = length_t<T>(),const length_t<T>& w = length_t<T>())
        : m_height(h),
        m_width(w)  {}

        rectangle_t(const rectangle_t& r)   {
            *this   = r;
        }

        rectangle_t& operator = (const rectangle_t& r)  {
            m_height    = r.height();
            m_width     = r.width();
            return *this;
        }

        length_t<T> height() const { return m_height; }
        length_t<T> width() const  { return m_width; }

        void height(const length_t<T>& l)  { m_height  = l; }
        void width(const length_t<T>& l)   { m_width   = l; }

        std::string repr() const  {
            std::ostringstream os;
            os << "[" << m_height << ", " << m_width << "]";
            return os.str();
        }

        private:

        length_t<T> m_height;
        length_t<T> m_width;
    };

    template<typename T>
    std::ostream& operator << (std::ostream& os, const rectangle_t<T>& r)   {
        os << r.repr();
        return os;
    }

    template<typename T>
    bool compare_rect_height (const rectangle_t<T>& r1, const rectangle_t<T>& r2)    {
        return r1.height() < r2.height();
    }

    template<typename T>
    bool compare_rect_width (const rectangle_t<T>& r1, const rectangle_t<T>& r2)    {
        return r1.width() < r2.width();
    }

    typedef rectangle_t<std::uint32_t> rect_t;
}

#endif
