#include <nachtigall/common/String.hpp>
#include <nachtigall/common/abstract/IRecoder.hpp>

#include <string>

namespace Nachtigall
{
    namespace Common
    {
        struct String::Impl
        {
            Impl()
                : data_() 
            {
            };

            explicit Impl(std::wstring const & str)
                : data_(str) 
            {
            };

            Impl(std::string const & localString, shared_ptr<IRecoder> fromEncoding)
                : data_()
            {
                fromEncoding->ToUnicode(localString, data_);
            };

            Impl(Impl const & rhs)
                : data_(rhs.data_)
            {
            };            

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
        
        std::wstring String::ToStdWString() const
        {
            return pImpl_->data_;
        };
    };
};
