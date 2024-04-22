#pragma once

using namespace std;

class dict_abstract {

public:

	virtual void add_dict(const char*) = 0;

	virtual void get_dict(const char*) = 0;
};

//class parser {
//public:
//
//	void read_text(const char*, int);
//
//	void write_result(const char*);
//};

class dict_map : public dict_abstract {
public:
	
	virtual void add_dict(const char*) override;

	virtual void get_dict(const char*) override;
};

class dict_unordered_map : public dict_abstract {
public:

	virtual void add_dict(const char*) override;

	virtual void get_dict(const char*) override;
};

class dict_vector : public dict_abstract {
public:

	virtual void add_dict(const char*) override;

	virtual void get_dict(const char*) override;
};

class dict_list : public dict_abstract {
public:

	virtual void add_dict(const char*) override;

	virtual void get_dict(const char*) override;
};

class dict_set : public dict_abstract {
public:

	virtual void add_dict(const char*) override;

	virtual void get_dict(const char*) override;
};

class dict_unordered_set : public dict_abstract {
public:

	virtual void add_dict(const char*) override;

	virtual void get_dict(const char*) override;
};

