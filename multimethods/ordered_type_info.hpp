#ifndef ORDERED_TYPE_INFO_HPP
#define ORDERED_TYPE_INFO_HPP

#include <typeinfo>

class OrderedTypeInfo
{
public:
    OrderedTypeInfo(const std::type_info& t)
        : pInfo_(&t)
    {
    }

    OrderedTypeInfo(const OrderedTypeInfo& other)
        : pInfo_(other.pInfo_)
    {
    }

    OrderedTypeInfo operator=(const OrderedTypeInfo& other)
    {
        if (static_cast<const OrderedTypeInfo>(*this) == other)
        {
            return *this;
        }

        pInfo_ = other.pInfo_;
        return *this;
    }

    bool before(const OrderedTypeInfo& other) const
    {
        return pInfo_->before(*other.pInfo_);
    }

    const char* name() const
    {
        return pInfo_->name();
    }

    friend bool operator==(const OrderedTypeInfo&, const OrderedTypeInfo&);
    friend bool operator!=(const OrderedTypeInfo&, const OrderedTypeInfo&);
    friend bool operator<(const OrderedTypeInfo&, const OrderedTypeInfo&);
    friend bool operator<=(const OrderedTypeInfo&, const OrderedTypeInfo&);
    friend bool operator>(const OrderedTypeInfo&, const OrderedTypeInfo&);
    friend bool operator>=(const OrderedTypeInfo&, const OrderedTypeInfo&);

private:
private:
    const std::type_info* pInfo_;
};

bool operator==(const OrderedTypeInfo& lhs, const OrderedTypeInfo& rhs)
{
    return *lhs.pInfo_ == *rhs.pInfo_;
}

bool operator!=(const OrderedTypeInfo& lhs, const OrderedTypeInfo& rhs)
{
    return !(lhs == rhs);
}

bool operator<(const OrderedTypeInfo& lhs, const OrderedTypeInfo& rhs)
{
    return lhs.before(rhs);
}

bool operator<=(const OrderedTypeInfo& lhs, const OrderedTypeInfo& rhs)
{
    return lhs < rhs || lhs == rhs;
}

bool operator>(const OrderedTypeInfo& lhs, const OrderedTypeInfo& rhs)
{
    return !(lhs < rhs);
}

bool operator>=(const OrderedTypeInfo& lhs, const OrderedTypeInfo& rhs)
{
    return lhs > rhs || lhs == rhs;
}

#endif
