#ifndef GCN_HGETTFFONT_HPP
#define GCN_HGETTFFONT_HPP

#include <string>
//#include <hgeTTF/FontManager.h> //hgeTTF ���̺귯���� ��Ŭ���
//#include <hgeTTF/Font.h>

#include "guichan/font.hpp"
#include "guichan/platform.hpp"

namespace gcn
{
    class Graphics;

	//HGE TTF ���̺귯���� �̿��� ��Ʈ Ŭ����
	//100111 �����ڵ� ����
    class GCN_EXTENSION_DECLSPEC HGETTFFont : public Font
    {
    public:
        
		//HGE TTF ��Ʈ ��ü �����͸� ���ڷ� ����
        HGETTFFont(hgeTTF::Font* font);
        ~HGETTFFont();
        virtual hgeTTF::Font *getFont() const;
        int getWidth(wchar_t character) const;


        //Font�κ��� ��ӹ��� �Լ���.
        int getWidth(const std::wstring& text) const;
        int getHeight() const;
        int getStringIndexAt(const std::wstring& text, int x) const;
        void drawString(Graphics *graphics, const std::wstring &text, int x, int y);

    protected:
        hgeTTF::Font *mHGEFont;
    };
}

#endif // end GCN_HGETTFFONT_HPP