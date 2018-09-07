
/** \brief suma dos flotantes
 *
 * \param primer flotante a sumar
 * \param segundo flotante a sumar
 * \return la suma de los parametros
 *
 */

    float sumar(float nro1, float nro2)
    {
        float resultado;

        resultado=nro1+nro2;
        return resultado;
    }
/** \brief resta dos flotantes
 *
 * \param primer flotante a restar
 * \param segundo restante a restar
 * \return la resta de los parametros
 *
 */

    float restar(float nro1, float nro2)
    {
        float resultado;

        resultado=nro1-nro2;
        return resultado;
    }
/** \brief division de dos flotantes
 *
 * \param primer flotante: será el dividendo
 * \param segundo flotante: será divisior
 * \return la division de los parametros
 *
 */

    float dividir(float nro1, float nro2)
    {
        float resultado;

        resultado=nro1/nro2;
        return resultado;
    }
/** \brief la multiplicación de dos flotantes
 *
 * \param primer flotante a multiplicar
 * \param segundo flotante a multiplicar
 * \return la multiplicaion de los parametros
 *
 */

    float multiplicar(float nro1, float nro2)
    {
        float resultado;

        resultado=nro1*nro2;
        return resultado;
    }
    /** \brief el factorial del primer numero ingresado
     *
     * \param primer numero a factorear
     * \return el factorial del parametro
     *
     */

    int factorearNro1 (int nro1)
    {
        int i;
        long resultado=1;

        for(i=1;i<=nro1;i++)
        {
            resultado=resultado*i;
        }
        return resultado;
    }
    /** \brief el factorial del segundo numero ingresado
     *
     * \param segundo numero a factorear
     * \return el factorial del parametro
     *
     */

    int factorearNro2 (int nro2)
    {
        int i;
        long resultado=1;

        for(i=1;i<=nro2;i++)
        {
            resultado=resultado*i;
        }
        return resultado;
    }

