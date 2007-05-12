#ifndef NACHTIGALL__COMMON__STRING_HPP
#define NACHTIGALL__COMMON__STRING_HPP

#include <string>

#include <boost/shared_ptr.hpp>
#include <boost/scoped_ptr.hpp>

using boost::shared_ptr;
using boost::scoped_ptr;

namespace Nachtigall
{
    namespace Common
    {
        class IRecoder;
        
        /// Class of unicode strings.
        /**
         * String class represents Unicode strings.
         */
        class String
        {
        public:
            /// Constructs an empty String
            String();
            
            /// Constructs String with contence of anotherString
            explicit String(std::wstring const & anotherString);

            /// Constructs String with contence of localString recoded using fromEncoding
            String(std::string const & localString, shared_ptr<IRecoder> fromEncoding);
            
            /// Constructs a copy of rhs
            String(String const & rhs);
            
            /// Assigns String from rhs
            String & operator=(String const & rhs);

            /// Assigns String from rhs
            String & operator=(std::wstring const & rhs);
            
            /// Destructor. Never throws.
            ~String() {};

            /// Swaps string with rhs. Never throws.
            void Swap(String const & rhs);

        private:
            class Impl;
            scoped_ptr<Impl> pImpl_;
        };
    };
};

#endif
