#ifndef NACHTIGALL__COMMON__IRECODER_HPP
#define NACHTIGALL__COMMON__IRECODER_HPP

#include <string>

namespace Nachtigall
{
    namespace Common
    {
        /// Character recode interface
        /**
         * Base class for all classes implement character recoding.
         * You have to redefine private DoToUnicode() function.
         */
        class IRecoder
        {
        public:
            /// Destructor. Never throws.
            virtual ~IRecoder() {};
            
            /// Converts string from @b from to @b to
            void ToUnicode(std::string const & from, std::wstring & to)
            {
                DoToUnicode(from, to);
            };

        private:
            virtual void DoToUnicode(from, to);
        };
    };
};

#endif
