#include <nachtigall/common/String.hpp>

#include <string>

namespace Nachtigall
{
    namespace Common
    {
        struct String::Impl
        {
            Impl();
            explicit Impl(std::wstring const & str)
                : data_(str) {};
            Impl(std::string const & localString, shared_ptr<IRecoder> fromEncoding);
            Impl(Impl const & rhs);

            std::wstring data_;
        };

        String::String()
            : pImpl_(new String::Impl()) {};
        
        String::String(std::wstring const & anotherString)
            : pImpl_(new String::Impl(anotherString))
        {            
        };
        
        String::String(std::string const & localString, shared_ptr<IRecoder> fromEncoding)
            : pImpl_(new String::Impl(localString, fromEncoding))
        {
        };
        
        String::String(String const & rhs)
            : pImpl_(new Impl(*rhs.pImpl_))
        {
        };
        
        String & String::operator=(String const & rhs)
        {
            String tmp(rhs);
            Swap(tmp);
            return *this;
        };
        
        String & String::operator=(std::wstring const & rhs)
        {
            String tmp(rhs);
            Swap(tmp);
            return *this;
        };
        
        void String::Swap(String & rhs)
        {
            pImpl_.swap(rhs.pImpl_);
        };        
    };
};
