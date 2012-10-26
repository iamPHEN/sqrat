namespace Sqrat{
    template<class C>
    class ImprovedAllocator :public DefaultAllocator<C> {
        static SQInteger setInstance(HSQUIRRELVM vm,C* instance)
        {
            sq_setinstanceup(vm, 1, instance);
            sq_setreleasehook(vm, 1, &DefaultAllocator<C>::Delete);
            return 0;
        }
    public:
        template <typename A1>
        static SQInteger iNew(HSQUIRRELVM vm) {
            return setInstance(vm, new C(
                Var<A1>(vm, 2).value
                ));
        }
        template <typename A1,typename A2>
        static SQInteger iNew(HSQUIRRELVM vm) {
            return setInstance(vm, new C(
                Var<A1>(vm, 2).value,
                Var<A2>(vm, 3).value
                ));
        }
        template <typename A1,typename A2,typename A3>
        static SQInteger iNew(HSQUIRRELVM vm) {
            return setInstance(vm, new C(
                Var<A1>(vm, 2).value,
                Var<A2>(vm, 3).value,
                Var<A3>(vm, 4).value
                ));
        }
        template <typename A1,typename A2,typename A3,typename A4>
        static SQInteger iNew(HSQUIRRELVM vm) {
            return setInstance(vm, new C(
                Var<A1>(vm, 2).value,
                Var<A2>(vm, 3).value,
                Var<A3>(vm, 4).value,
                Var<A4>(vm, 5).value
                ));
        }
        template <typename A1,typename A2,typename A3,typename A4,typename A5>
        static SQInteger iNew(HSQUIRRELVM vm) {
            return setInstance(vm, new C(
                Var<A1>(vm, 2).value,
                Var<A2>(vm, 3).value,
                Var<A3>(vm, 4).value,
                Var<A4>(vm, 5).value,
                Var<A5>(vm, 6).value
                ));
        }
        template <typename A1,typename A2,typename A3,typename A4,typename A5,typename A6>
        static SQInteger iNew(HSQUIRRELVM vm) {
            return setInstance(vm, new C(
                Var<A1>(vm, 2).value,
                Var<A2>(vm, 3).value,
                Var<A3>(vm, 4).value,
                Var<A4>(vm, 5).value,
                Var<A5>(vm, 6).value,
                Var<A6>(vm, 7).value
                ));
        }
        template <typename A1,typename A2,typename A3,typename A4,typename A5,typename A6,typename A7>
        static SQInteger iNew(HSQUIRRELVM vm) {
            return setInstance(vm, new C(
                Var<A1>(vm, 2).value,
                Var<A2>(vm, 3).value,
                Var<A3>(vm, 4).value,
                Var<A4>(vm, 5).value,
                Var<A5>(vm, 6).value,
                Var<A6>(vm, 7).value,
                Var<A7>(vm, 8).value
                ));
        }
        template <typename A1,typename A2,typename A3,typename A4,typename A5,typename A6,typename A7,typename A8>
        static SQInteger iNew(HSQUIRRELVM vm) {
            return setInstance(vm, new C(
                Var<A1>(vm, 2).value,
                Var<A2>(vm, 3).value,
                Var<A3>(vm, 4).value,
                Var<A4>(vm, 5).value,
                Var<A5>(vm, 6).value,
                Var<A6>(vm, 7).value,
                Var<A7>(vm, 8).value,
                Var<A8>(vm, 9).value
                ));
        }
        template <typename A1,typename A2,typename A3,typename A4,typename A5,typename A6,typename A7,typename A8,typename A9>
        static SQInteger iNew(HSQUIRRELVM vm) {
            return setInstance(vm, new C(
                Var<A1>(vm, 2).value,
                Var<A2>(vm, 3).value,
                Var<A3>(vm, 4).value,
                Var<A4>(vm, 5).value,
                Var<A5>(vm, 6).value,
                Var<A6>(vm, 7).value,
                Var<A7>(vm, 8).value,
                Var<A8>(vm, 9).value,
                Var<A9>(vm, 10).value
                ));
        }
    };


    template<class C,  class A = ImprovedAllocator<C> >
    class ImprovedClass :public Class<C,A>{
        ImprovedClass& BindConstructor(SQFUNCTION method,SQInteger nParams){
            HSQUIRRELVM vm = Object::GetVM();
			HSQOBJECT& classObj = ClassType<C>::ClassObject(vm);
            sq_pushobject(vm, classObj);
            sq_pushstring(vm,_SC("constructor"), -1);
            sq_newclosure(vm, method, 0);
            sq_setparamscheck(vm,nParams+1,NULL);
            sq_newslot(vm, -3, false);
            sq_pop(vm, 1);
            return *this;
        }
    public:
        // Create a new table
        ImprovedClass(HSQUIRRELVM v = DefaultVM::Get(), bool createClass = true) : Class<C,A>(v,createClass) {}
        template<class A1>
        ImprovedClass& Ctor() {
            return BindConstructor(A::template iNew<A1>,1);
        }
        template<class A1,class A2>
        ImprovedClass& Ctor() {
            return BindConstructor(A::template iNew<A1,A2>,2);
        }
        template<class A1,class A2,class A3>
        ImprovedClass& Ctor() {
            return BindConstructor(A::template iNew<A1,A2,A3>,3);
        }
        template<class A1,class A2,class A3,class A4>
        ImprovedClass& Ctor() {
            return BindConstructor(A::template iNew<A1,A2,A3,A4>,4);
        }
        template<class A1,class A2,class A3,class A4,class A5>
        ImprovedClass& Ctor() {
            return BindConstructor(A::template iNew<A1,A2,A3,A4,A5>,5);
        }
        template<class A1,class A2,class A3,class A4,class A5,class A6>
        ImprovedClass& Ctor() {
            return BindConstructor(A::template iNew<A1,A2,A3,A4,A5,A6>,6);
        }
        template<class A1,class A2,class A3,class A4,class A5,class A6,class A7>
        ImprovedClass& Ctor() {
            return BindConstructor(A::template iNew<A1,A2,A3,A4,A5,A6,A7>,7);
        }
        template<class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8>
        ImprovedClass& Ctor() {
            return BindConstructor(A::template iNew<A1,A2,A3,A4,A5,A6,A7,A8>,8);
        }
        template<class A1,class A2,class A3,class A4,class A5,class A6,class A7,class A8,class A9>
        ImprovedClass& Ctor() {
            return BindConstructor(A::template iNew<A1,A2,A3,A4,A5,A6,A7,A8,A9>,9);
        }
    };

	
template<class C, class B, class A = ImprovedAllocator<C> >
class ImprovedDerivedClass : public ImprovedClass<C,A>
{
public:
    ImprovedDerivedClass(HSQUIRRELVM v = DefaultVM::Get()) : ImprovedClass<C, A>(v, false) {
        if(!ClassType<C>::Initialized(v)) {
            HSQOBJECT& classObj = ClassType<C>::ClassObject(v);
            sq_resetobject(&classObj);

            sq_pushobject(v, ClassType<B>::ClassObject(v));
            sq_newclass(v, true);
            sq_getstackobj(v, -1, &classObj);
            sq_addref(v, &classObj); // must addref before the pop!
            sq_pop(v, 1);

            InitDerivedClass(v);
            ClassType<C>::Initialized(v) = true;
        }
    }

protected:
    void InitDerivedClass(HSQUIRRELVM vm) {
        ClassType<C>::CopyFunc(vm) = &A::Copy;

        // push the class
        sq_pushobject(vm, ClassType<C>::ClassObject(vm));

        // add the default constructor
        sq_pushstring(vm,_SC("constructor"), -1);
        sq_newclosure(vm, &A::New, 0);
        sq_newslot(vm, -3, false);

        // clone the base classes set table (static)
        HSQOBJECT& setTable = ClassType<C>::SetTable(vm);
        sq_resetobject(&setTable);
        sq_pushobject(vm, ClassType<B>::SetTable(vm));
        sq_pushstring(vm,_SC("__setTable"), -1);
        sq_clone(vm, -2);
        sq_remove(vm, -3);
        sq_getstackobj(vm, -1, &setTable);
        sq_addref(vm, &setTable);
        sq_newslot(vm, -3, true);

        // clone the base classes get table (static)
        HSQOBJECT& getTable = ClassType<C>::GetTable(vm);
        sq_resetobject(&getTable);
        sq_pushobject(vm, ClassType<B>::GetTable(vm));
        sq_pushstring(vm,_SC("__getTable"), -1);
        sq_clone(vm, -2);
        sq_remove(vm, -3);
        sq_getstackobj(vm, -1, &getTable);
        sq_addref(vm, &getTable);
        sq_newslot(vm, -3, true);

        // override _set
        sq_pushstring(vm, _SC("_set"), -1);
        sq_pushobject(vm, setTable); // Push the set table as a free variable
        sq_newclosure(vm, sqVarSet, 1);
        sq_newslot(vm, -3, false);

        // override _get
        sq_pushstring(vm, _SC("_get"), -1);
        sq_pushobject(vm, getTable); // Push the get table as a free variable
        sq_newclosure(vm, sqVarGet, 1);
        sq_newslot(vm, -3, false);

        // add weakref (apparently not provided by default)
        sq_pushstring(vm, _SC("weakref"), -1);
        sq_newclosure(vm, &Class<C, A>::ClassWeakref, 0);
        sq_newslot(vm, -3, false);

        // pop the class
        sq_pop(vm, 1);
    }
};
}
