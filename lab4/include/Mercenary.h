class Mercenary
{
	public:	
		void *character;
		const char* type;
		
		Mercenary(void *c, const char *t) : character(c), type(t) {}	
};
